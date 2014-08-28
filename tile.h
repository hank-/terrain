#ifndef TILE_H
#define TILE_H

class tile{

 private:
  char type;//'w'=water 's'=sand 'g'=grass 'm'=mountain
  char sym;
  int color;
 public:
  tile();
  void setType(char a);
  char getType();
  void setSym(char a);
  char getSym();  
  void setColor(int a);
  int getColor();
};
#endif
