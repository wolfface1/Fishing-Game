/* 
 * File:   seaTable.h
 * Author: sam
 *
 * Created on 22 July 2014, 14:30
 */

#ifndef BYTETABLE_H
#define	BYTETABLE_H

#include <QtGlobal>


class byteTable {
  public:
    byteTable();
    byteTable(int rows, int columns);
    virtual ~byteTable();
   
    byteTable &operator=(const byteTable &other);
    
    void reDim(int rows, int columns);
    bool setRawByte(int x, int y, quint8 rawByte);
    bool setBytetoAll(quint8 rawByte);
    quint8 returnByte(int x, int y);
    bool loadFromFile(const char *Path);
    bool saveToFile(const char *Path);
    bool constructTable();
    void deleteTable();
    void clearTable();
    bool valid() {return !Null;};
    int rows() {return rowCount;};
    int columns() {return colCount;};
  private:
    quint8 **table;
    int rowCount;
    int colCount;
    bool Null;
};

#endif	/* SEATABLE_H */

