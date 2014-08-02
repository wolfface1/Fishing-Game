/*
 * File:   main.cpp
 * Author: sam
 *
 * Created on 15 April 2014, 22:34
 */

#include <QApplication>
#include <QtGui/qwidget.h>
#include "MainWindow.h"

int main(int argc, char *argv[]) {
  // initialize resources, if needed
  // Q_INIT_RESOURCE(resfile);

  QApplication app(argc, argv);
  
  //init window
  MainWindow win;
  win.setFixedSize(win.size()); //set it as a fixed size, as its size for now
  win.show();

  return app.exec();
}
