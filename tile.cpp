#include <iostream>
#include "tile.h"
#include <ncurses.h>

tile::tile(){
 type = 0;
 sym = 0;
 color = 0;
}

void tile::setType(char a){
 type = a;
}

char tile::getType(){
 return type;
}

void tile::setSym(char a){
 sym = a;
}

char tile::getSym(){
 return sym;
}

void tile::setColor(int a){
 color = a;
}

int tile::getColor(){
 return color;
}




/*tile::tile(char tileType, char tileLook, int tileColor){
 start_color();
 init_pair(1, 1, COLOR_BLACK);
 init_pair(2, COLOR_YELLOW, COLOR_BLACK);
 init_pair(3, COLOR_GREEN, COLOR_BLACK);
 init_pair(4, COLOR_BLUE, COLOR_BLACK);
 init_pair(5, COLOR_CYAN, COLOR_BLACK);
 init_pair(6, COLOR_MAGENTA, COLOR_BLACK);
 init_pair(7, COLOR_RED, COLOR_BLACK);
 init_pair(8, COLOR_WHITE, COLOR_BLACK);
 init_pair(9, COLOR_WHITE, COLOR_BLACK);
 init_pair(10, COLOR_WHITE, COLOR_BLACK);
 
 type = tileType;
 look = tileLook;
 color = tileColor;
}*/
