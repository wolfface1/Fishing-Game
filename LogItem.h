/*
 * File:   LogItem.h
 * Author: sam
 *
 * Created on 20 July 2014, 13:51
 */

#ifndef LOGITEM_H
#define	LOGITEM_H
#include <qbytearray.h>

/*
 * Null : type = 0
 * Error : type = 1
 * Click : type = 2
 * story : type = 3
 * 
 * 
 *
*/

#include <QString>

enum{
  tNull = 0,
  tError = 1,
  tClick = 2,
  tStory = 3
};

class LogItem {
public:
    LogItem();
    LogItem(int x, int y);
    LogItem(QString ErrorString);
    virtual ~LogItem();
    LogItem(const LogItem &other); //copy constructer

    LogItem &operator=(const LogItem &other);    
    inline bool isValid() const {return (type != 0);};
    inline static const LogItem Null() {LogItem item; return item;}
    inline static const LogItem FromString(QString string) {LogItem item; if(item.fromString(string)){return item;}else{return LogItem::Null();}}
    
    //marked with * need to be appended to when new log type added then also add return function and set function
    //string handeling
    bool fromString(QString string); //*
    QString toString() const;        //*
    
    // error type implement
    void setTypeError(QString description = QString("Unknown"));
    void setTypeError(char *string);
    QString asLogError() const;
    
    //click type implement
    void setTypeClick(int x, int y);
    int *asLogClick() const;
    
    void setTypeStory(int eventType);
    int asStoryType() const;
    
    int returnType();
private:
    int type;
    void delMem();
    void copyStr(char *p1, char *p2);
    int countStr(char *string);
    void *data;
};

#endif	/* LOGITEM_H */

