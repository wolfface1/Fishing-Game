/* 
 * File:   GameLog.h
 * Author: sam
 *
 * Created on 20 July 2014, 12:41
 */

#ifndef GAMELOG_H
#define	GAMELOG_H

#include <QObject>
#include <QThread>
#include <QReadWriteLock>
#include <QVector>
#include "LogItem.h"

class GameLog : public QObject {
  Q_OBJECT
  QThread workerThread;
  
  public:
    GameLog();
    virtual ~GameLog();
   
    bool isEmpty() const;
  private:
    QVector<LogItem> Log;
    
  signals:
    void logText(QString text);
    void clickCell(int x, int y);
    void logCleared();
  public slots:
    void logClick(int x,int y);
    void logError(QString error);
    void LogText(QString text);
    
    void ClearLog();
    void LoadLogFile(QString LogfilePath);
    void SaveLogFile(QString LogfilePath);    
    void RunLog();
};
#endif	/* GAMELOG_H */

