/* 
 * File:   MainWindow.h
 * Author: sam
 *
 * Created on 15 April 2014, 22:36
 */

#ifndef _MAINWINDOW_Hupdate
#define	_MAINWINDOW_H

#include "ui_MainWindow.h"
#include "GameLog.h"
#include <QDebug>

class MainWindow : public QMainWindow {
  Q_OBJECT
  QThread workerThread;
  
public:
  MainWindow();
  virtual ~MainWindow();
private:
  Ui::MainWindow widget;
  void save(QString PathtoFile);
  
  GameLog *Logger;
  QString FilePath;
  QString setFilePath(QString PathtoFile);
  
public slots:
  void aboutqt();
  void save();
  void saveAs();
  void open();
signals:
  void error(QString error);
  void saveLog(QString Path);
  void loadLog(QString Path);
  void clearLog();
  void runLog();
private slots:
};

#endif	/* _MAINWINDOW_H */
