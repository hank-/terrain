#include "field.h"
#include <iostream>
#include <ncurses.h>
using namespace std;

int x = 0; //Cursor position
int y = 0; //

void moveCurs(int a, int b){ //Moves cursor by the amount given as arguments
 y += a;
 x += b;
 move(y,x);
}

void generateField(){

}

void menuScreen(){ //Draws main menu
 int menuWidth = 60;
 int menuHeight = 30;

 move(0,0);
 for(int i=0; i<menuWidth; i++)
  printw("@");

 move(menuHeight-2,0);
 for(int i=0; i<menuWidth+1; i++)
  printw("~");

 for(int i=0; i<menuHeight; i++){
  move(i, 0); 
  printw("@");
  move(i, menuWidth);
  printw("@");
 }
 
 move(menuHeight,0);
 for(int i=0; i<menuWidth+1; i++)
  printw("@");

 move(menuHeight/10, (menuWidth/2)-(menuWidth/10));
 printw("Welcome to Terrain");

 move((menuHeight/10)+1*(menuHeight/10), (menuWidth/2)-(menuWidth/10));
 printw("(a) New Map"); 

 move((menuHeight/10)+2*(menuHeight/10), (menuWidth/2)-(menuWidth/10));
 printw("(b) New Game");

 move((menuHeight/10)+3*(menuHeight/10), (menuWidth/2)-(menuWidth/10));
 printw("(c) Load Game");

 move((menuHeight/10)+4*(menuHeight/10), (menuWidth/2)-(menuWidth/10));
 printw("(d) Quit");

 attron(COLOR_PAIR(3));
 move(menuHeight-1,1);
 y = menuHeight-1;
 x = 1;
 refresh();
 
 char input;
 while(input != 'd'){
  input = 1;
  move(menuHeight-1,1);
  printw(">");
  input = getch(); 
  getch();
  if(input == 'a'){
   generateField();
   move(menuHeight-1,1);
   for(int i=0; i<menuWidth-22; i++)
    addch(' ');
   refresh();
  }//else if(input == '1') 
    //generateField();
  //else if(input == 'c')
  else if(input == 'd'){ 
  }else{
   move(menuHeight-1,1);
   printw("Invalid");
   getch();
   move(menuHeight-1,1);
   for(int i=0; i<menuWidth-22; i++)
    addch(' ');
   refresh();
  }
 }
}

int main(){
 
 initscr();
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

 menuScreen();
  
 endwin();
 return 0;

}
