/* 
 * File:   seaWidget.h
 * Author: sam
 *
 * Created on 20 April 2014, 12:33
 */

#ifndef SEAWIDGET_H
#define	SEAWIDGET_H

#include <QWidget>
#include <QMouseEvent>
#include <QDebug>
#include <QPainter>
#include "byteTable.h"

enum TBitMask{
  //uncovered = quint8(0), //00000000
  covered = quint8(1), //00000001
  fish = quint8(2) //00000010
};

class seaWidget : public QWidget {
  Q_OBJECT
  
  public:
    seaWidget(QWidget *parent = 0, int columns = 20, int rows = 20);
    virtual ~seaWidget();
    void setFish(int x, int y, bool fish = true); //set a fish
    void setCovered(int x, int y, bool uncover = true);  //set covered
    bool isCovered(int x, int y);
    void loadTable(byteTable Table);
    
  protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void resizeEvent(QResizeEvent *event);
  private:
    //void deleteTable(); //a nice little convenience function that cleanly deletes the table on the heap
    
    QString printBinary(quint8 byte);
    QPixmap drawImage(quint8 code);
    void cellClicked(int x, int y);
    void checkCell(int x, int y);  //checks the cell and changes the stats.
    
    byteTable table;
    int Cwidth; int Cheight;
  public:
    void loadTable(QString path);
    void saveTable(QString path);
  signals:
    void fishFound();
    void cellHit(int x, int y);
    void error(QString error);
  public slots:
    void ClickFromLog(int x, int y);
};

#endif	/* SEAWIDGET_H */

