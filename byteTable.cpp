#include "byteTable.h"
#include "iostream"
#include "fstream"

byteTable::byteTable(){
  Null = true;
}

byteTable::byteTable(int rows, int columns){
  Null = false;
  colCount = rows;
  rowCount = columns;
  constructTable();
}

byteTable::~byteTable(){
  deleteTable();
}
   
byteTable& byteTable::operator=(const byteTable& other){
  reDim(other.rowCount, other.colCount);
  
  for(int x = 0; x < colCount; x++){
    for(int y = 0; y < rowCount; y++){
      table[x][y] = other.table[x][y];
    }
  }
  
  Null = false;
}

   
void byteTable::reDim(int rows, int columns){
  deleteTable();
  rowCount = rows;
  colCount = columns;
  constructTable();
}

bool byteTable::setRawByte(int x, int y, quint8 rawByte){
  if(!Null){
    table[x][y] = rawByte;
    return true;
  }else{
    return false;
  }
}

bool byteTable::setBytetoAll(quint8 rawByte){
  for(int x = 0; x < colCount; x++){
    for(int y = 0; y < rowCount; y++){
      table[x][y] = rawByte;
    }
  }
}


quint8 byteTable::returnByte(int x, int y){
  quint8 byte;
  
  if (!Null){
    byte = table[x][y];
    return byte;
  }else{
    return 0;
  }
  
}

bool byteTable::loadFromFile(const char *Path){
  std::ifstream in(Path);
  
  if(!in || Null){
    return false;
  }
  
  in >> colCount;
  in >> rowCount;
  
  for(int y = 0; y < rowCount; y++){
    for(int x = 0; x < colCount; x++){
      in >> table[x][y];
    }
  }
  
  in.close();
  
  return true;
}

bool byteTable::saveToFile(const char* Path){
  std::ofstream out(Path);
  
  if(!out || Null){
    return false;
  }
  
  out << rowCount << ' ' << colCount << "\n";
  
  for(int y = 0; y < rowCount; y++){
    for(int x = 0; x < colCount; x++){
      out << table[x][y];
    }
    out << '\n';
  }
  
  out.close();
  return true;
}


bool byteTable::constructTable(){
  if (!Null){
    return false;
  }else{
    //put array on heap
    table = new quint8* [colCount];
  
    for(int i = 0; i < colCount; i++){
      table[i] = new quint8[rowCount];
    }
    Null = false;
  }
}  

void byteTable::deleteTable(){
  
  if (!Null){
    //delete allocated memory
    for(int i = 0; i < colCount; i++){
      delete[] table[i];
    }
  
    delete[] table;
    Null = true;
  }  
}


void byteTable::clearTable(){
  for(int x = 0; x < colCount; x++){
    for(int y = 0; y < rowCount; y++){
      setRawByte(x, y, 0);
    }
  }
}