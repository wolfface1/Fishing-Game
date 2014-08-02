    
#include "seaWidget.h"
#include <QObject>

seaWidget::seaWidget(QWidget* parent, int columns, int rows): QWidget(parent){
  table.reDim(columns, rows);
  table.setBytetoAll(covered);
}


seaWidget::~seaWidget(){
} 

void seaWidget::setFish(int x, int y, bool fish){
  quint8 BMask;
  if (fish){
    BMask = fish | table.returnByte(x, y); //set the fish bit
  }else{
    BMask = ~fish & table.returnByte(x, y); //unset fish bit
  }
  table.setRawByte(x, y, BMask);
}

void seaWidget::setCovered(int x, int y, bool setCoverBit){
  quint8 BMask;
  if (setCoverBit){
    BMask = covered | table.returnByte(x, y); //set covered bit
  }else{
    BMask = ~covered & table.returnByte(x, y); //unset covered bit
    qDebug() << "BMask uncovered:" << printBinary(BMask);
  }
  table.setRawByte(x, y, BMask);
}

bool seaWidget::isCovered(int x, int y){
  if ((table.returnByte(x, y) & covered) == covered){
    return true;
  }else{
    return false;
  }
}

void seaWidget::loadTable(byteTable Table){
  table = Table;
}


//I want implement some code that only updates particular regions, this would involve
//using the event object, and some code to work out which cells need updating
void seaWidget::paintEvent(QPaintEvent *event){
  QPixmap pixmap; 
  
  QPainter painter(this);
  
  painter.setPen(Qt::blue);
  painter.setBrush(QBrush(Qt::cyan));
  //painter.drawRect(0, 0, width(), height());
  
  for (int x = 0; x < table.columns(); x++){
    for(int y = 0; y < table.rows(); y++){
      pixmap = drawImage(table.returnByte(x, y));
      painter.drawPixmap(x * Cwidth, y * Cheight, pixmap);
    }
  }
  
  //qDebug() << "paintevent";
}

void seaWidget::mousePressEvent(QMouseEvent *event){
  int cellx, celly;
  
  cellx = event->x() / Cwidth;
  celly = event->y() / Cheight;
  
  cellClicked(cellx, celly); //transfer to table
  
  //qDebug() << "mouseClicked";
  
}

void seaWidget::resizeEvent(QResizeEvent *event){
  
  //calculate new cell dimensions this is probably not needed as we are not allowing resizing
  //but it will lighten the load on the constructor :P
  Cwidth = width() / table.columns();
  Cheight = height() / table.rows();
  
  repaint();
  qDebug() << "resized Cell width:" << width() << ", Cell Height:" << height(); 
}

void seaWidget::cellClicked(int x, int y){
  setCovered(x, y, false); //set the uncovered bit
  update();
  
  emit cellHit(x, y);
  //qDebug() << "Cell, x:" << x << "y:" << y << "clicked.";
}

void seaWidget::checkCell(int x, int y){
  char c = table.returnByte(x, y);
  
  if ((c & covered) == covered){
    return;
  }
  
  if ((c & fish) == fish){
    emit fishFound();
  }
}

QString seaWidget::printBinary(quint8 byte){
  QString output;
  
  for (int i = 0; i < 8; i++) {
    if (((byte << i) & 128)){
      output.append('1');
    }else{
      output.append('0');
    }
  }
  
  return output;
}

QPixmap seaWidget::drawImage(quint8 code){
  QPixmap pMap(Cwidth, Cheight);
  
  QPainter p(&pMap);
  
  p.setPen(Qt::gray);
  p.setBrush(QBrush(Qt::cyan));
  p.drawRect(pMap.rect());
  
  p.setPen(Qt::black);
  
  if ((code & covered) == covered){
    p.drawText(Cwidth / 2, Cheight / 2, "c");
  }else{
    if (((code & fish) == fish)){
      p.drawText(Cwidth / 2, Cheight / 2, "f");
    }else{
      p.drawText(Cwidth / 2, Cheight / 2, "n");
    }
  }
  p.end();
  
  return pMap;
}

void seaWidget::ClickFromLog(int x, int y){
  setCovered(x, y, false); //set the uncovered bit
  update();  
}

void seaWidget::loadTable(QString path){
  table.loadFromFile(path.toLocal8Bit().data());
}

void seaWidget::saveTable(QString path){
  if (!table.saveToFile(path.toLocal8Bit().data())){
    emit error("Unable to save table.");
  }
}  
  
