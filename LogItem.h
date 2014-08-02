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
 * 
 * 
 * 
 *
*/

#include <QString>

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
    
    void setTypeError(QString description = QString("Unknown"));
    void setTypeError(char *string);
    void setTypeClick(int x, int y);
    bool fromString(QString string);
    
    int returnType();
    QString toString() const;
    int *asLogClick() const;
    QString asLogError() const;
private:
    int type;
    void delMem();
    void copyStr(char *p1, char *p2);
    int countStr(char *string);
    void *data;
};

#endif	/* LOGITEM_H */

