
#include "LogItem.h"
#include <qstring.h>
#include <cmath>
#include <QObject>
#include <QDebug>

//#define charperInt static_cast<int>(ceil(sizeof(int) / sizeof(char)))

LogItem::LogItem(){
  type = 0;
}

LogItem::LogItem(int x, int y){
  type = 0;
  setTypeClick(x, y);
}

LogItem::LogItem(QString ErrorString){
  type = 0;
  setTypeError(ErrorString);
}

LogItem::LogItem(const LogItem& other){
  type = 0;
  *this = other;
}

LogItem& LogItem::operator=(const LogItem& other){
  if (this == &other){ // Same object?
   return *this;
  }
  
  switch(other.type){
    case 0:
      type = 0;
      break;
    case 1:
      char *chara;
      chara = (char*) other.data;
      setTypeError(chara);
      break;
    case 2:
      int *inta;
      inta = (int *) other.data;
      setTypeClick(inta[0], inta[1]);
      break;
    default:
      type = 0;
      break;
  }
  return *this;
}

LogItem::~LogItem(){
  delMem();
}

void LogItem::setTypeError(QString description){

  setTypeError(description.toLocal8Bit().data());
  
}

void LogItem::setTypeError(char *string){
  delMem();
  type = 1;
  
  char *chara = new char[countStr(string)];
  copyStr(string, chara);
  
  data = chara;  
}

void LogItem::setTypeClick(int x, int y){
  int *d;
  
  delMem();
  type = 2;
  
  d = new int[1];
  d[0] = x;
  d[1] = y;
  data = d;
}

int LogItem::returnType(){
  return type;
}

bool LogItem::fromString(QString string){
  int middle = string.indexOf(">");
  bool ok1 = true; bool ok2 = true;
  
  switch (string.left(middle).toInt()){
    case 0:
      break;
    case 1:
      setTypeError(string.mid(middle + 1, string.count()));
      break;
    case 2:
      int first; int x; int y;
      string.remove(0, middle + 1);
      first = string.indexOf(']');
      
      //qDebug() << string.mid(1,first - 1);
      x = string.mid(1,first - 1).toInt(&ok1);
      
      first = string.lastIndexOf('[') + 1;
      //qDebug() << string.mid(first,string.count() - (first + 1));
      y = string.mid(first,string.count() - (first + 1)).toInt(&ok2);
      
      if(ok1 && ok2){
        setTypeClick(x, y);
      }
      break;
    default:
      return false;
  }
  return ok1 && ok2;
}

//all this does is stick the 'int type' infront of data in a string and returns it
QString LogItem::toString() const{
  QString str;
  switch (type){
    case 0:
      return " > "; //return a null value
      break;
    case 1: //if type error
      char *chara;
      chara = (char *) data;
      str = QString("%1>%2").arg(type).arg(QString::fromLocal8Bit(chara));
      break;
    case 2: //if type click
      int *xy;
      xy = (int *) data;
      str = QString("%1>[%2][%3]").arg(type).arg(xy[0]).arg(xy[1]);
      break;
    default:
      //emit error("Unidentified type in logitem.")
      return QString::null;
  }
  return str;
}

int *LogItem::asLogClick() const{
  int *inta;
  
  inta = (int *) data;
  
  return inta;
}

QString LogItem::asLogError() const{
  char * chara;
  
  chara = (char *) data;
  
  return QString::fromLocal8Bit(chara);
}

void LogItem::delMem(){
  if (data == 0){
    return;
  }else{
    switch(type){
      case 0:
        break;
      case 1:
        char *chara;
        chara = (char*) data;
        delete[] chara;
        type = 0;
        break;
      case 2:
        int *inta;
        inta = (int *) data;
        delete[] inta;
        type = 0;
        break;
      default:
        type = 0;
        break;
    }
  }  
}

//copy p1 into p2
void LogItem::copyStr(char* from, char* into){
  int i = 0;
  
  while(from[i] != '\0'){
    into[i] = from[i];
    i++;
  }
  into[i] = from[i];
}

int LogItem::countStr(char* string){
  int i;
  
  while(i <= 1000){
    if (string[i] == '\0'){
      return i;
    }
    i++;
  }
  return 0;
}

