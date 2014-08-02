/*
 * File:   MainWindow.cpp
 * Author: sam
 *
 * Created on 15 April 2014, 22:36
 */

#include "MainWindow.h"
#include "seaWidget.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QDir>

MainWindow::MainWindow() {
  widget.setupUi(this);
  
  Logger = new GameLog();
  Logger->moveToThread(&workerThread);
  
  connect(widget.actionAbout_Qt, SIGNAL(triggered()), this, SLOT(aboutqt()));
  connect(widget.actionQuit, SIGNAL(triggered()), this, SLOT(close()));
  connect(widget.actionSave, SIGNAL(triggered()), this, SLOT(save()));
  connect(widget.actionSave_As, SIGNAL(triggered()), this, SLOT(saveAs()));
  connect(widget.actionOpen, SIGNAL(triggered()), this, SLOT(open()));
  connect(this, SIGNAL(error(QString)), Logger, SLOT(logError(QString)));
  
  connect(widget.W_seaTable, SIGNAL(cellHit(int, int)), Logger, SLOT(logClick(int, int)));
  connect(widget.W_seaTable, SIGNAL(error(QString)), Logger, SLOT(logError(QString)));
  
  //thread communication
  connect(Logger, SIGNAL(logText(QString)), widget.TB_Log, SLOT(append(QString)));
  connect(Logger, SIGNAL(logCleared()), widget.TB_Log, SLOT(clear()));
  connect(this, SIGNAL(clearLog()), Logger, SLOT(ClearLog()));
  connect(this, SIGNAL(saveLog(QString)), Logger, SLOT(SaveLogFile(QString)));
  connect(this, SIGNAL(loadLog(QString)), Logger, SLOT(LoadLogFile(QString)));
  connect(&workerThread, SIGNAL(finished()), Logger, SLOT(deleteLater()));
  
  workerThread.start();
  
  widget.W_seaTable->setEnabled(true);
  widget.W_seaTable->setVisible(true);
}

MainWindow::~MainWindow() {
  workerThread.quit();
  workerThread.wait();  
}

void MainWindow::aboutqt(){
  QMessageBox::aboutQt(this, this->windowTitle());
}

void MainWindow::save(QString PathtoFile){
  Logger->SaveLogFile(PathtoFile + ".slog");
  widget.W_seaTable->saveTable(PathtoFile + ".stab");
}

QString MainWindow::setFilePath(QString PathtoFile){
  FilePath = PathtoFile.remove(PathtoFile.indexOf('.'), PathtoFile.count());
  return FilePath;
}


void MainWindow::save(){
  if(FilePath.isEmpty()){
    saveAs();
  }else{
    save(FilePath);
  } 
}

void MainWindow::saveAs(){
  QString str = QFileDialog::getSaveFileName(this, "Please specify save file.", QDir::homePath(), "Sea Log (*.slog)");
  if (!str.isEmpty()){
    setFilePath(str);
    save(FilePath);
  }
}

void MainWindow::open(){
  QString str = QFileDialog::getOpenFileName(this, "Please specify a file to open.", QDir::homePath(), "Sea Log (*.slog)");
  if (!str.isEmpty()){
    setFilePath(str); 
    if(!Logger->isEmpty() && QMessageBox::question(this, "Warning", "Would you like to save the Log?", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes) == QMessageBox::Yes){
      save();
    }
    
  
    emit clearLog();
    emit loadLog(FilePath + ".slog");
  
    widget.W_seaTable->loadTable(FilePath + ".stab");
  
    //emit runLog();
  }
}
