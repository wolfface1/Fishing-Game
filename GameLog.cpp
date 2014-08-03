#include <qvector.h>

#include "GameLog.h"
#include <QTimer>
#include <QFile>
#include <QTextStream>

GameLog::GameLog(){
}

GameLog::~GameLog(){
  
}

void GameLog::RunLog(){
  int *inta;
  LogItem item;
  
  if (Log.isEmpty()){
    emit logText("GameLog: Log contains no log data, cannot create table from log");
    return;
  }else{
    foreach(item, Log){
      if (item.returnType() == 2){
	inta = item.asLogClick();
	emit clickCell(inta[0], inta[1]);
      }else{
	//do nothing
      }	
    }
  }
}

void GameLog::ClearLog(){
  Log.clear();
  emit logCleared();
}

bool GameLog::isEmpty() const{
  return Log.empty();
}


void GameLog::LoadLogFile(QString LogfilePath){
  QFile file(LogfilePath);
  LogItem item;
  int *inta;
  
  if (!Log.empty()){
    emit logText("GameLog: Log contains log data, cannot load data from file");
    return;
  }  
  
  if (!file.open(QFile::ReadOnly)){
    emit logText("GameLog: unable to open log file for reading");
    return;
  }
  
  QTextStream stream(&file);
  
  while(!stream.atEnd()){
    if(!item.fromString(stream.readLine())){emit logText("File corrupted"); return;};
    inta = item.asLogClick();
    Log.append(item);
    emit logText(QString("Cell[%1][%2], clicked").arg(inta[0]).arg(inta[1]));
  }
  emit logText("------- Log Loaded -------");
  stream.flush();
  file.close();
}

void GameLog::SaveLogFile(QString LogfilePath){
  QFile file(LogfilePath);
  LogItem item;
  
  if (!file.open(QFile::WriteOnly)){
    emit logText("GameLog: unable to open log file for writing");
    return;
  }
  
  QTextStream stream(&file);
  
  foreach(item, Log){
    stream << item.toString() << "\n";
  }
  
  emit logText("-------Log Saved-------");
  stream.flush();
  file.close();
}

void GameLog::logClick(int x, int y){
  LogItem item(x, y);
  Log.append(item);
  
  emit logText(QString("Cell[%1][%2], clicked").arg(x).arg(y));
}

void GameLog::logError(QString error){
  LogItem item(error);
  Log.append(item);
  
  emit logText(QString("Error: %1").arg(error));
}

void GameLog::LogText(QString text){
  emit logText(text);
}
