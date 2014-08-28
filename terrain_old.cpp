#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <ncurses.h>
using namespace std;

const int width  = 1000;
const int height = 1000;
const int winWidth = 100;
const int winHeight = 60;
int genFactor = 0;
int range = 0;
int cityGen = 0;
float multiplyer = 0;

int x = 0;
int y = 0;
int winX = 0;
int winY = 0;
int scrollRate = 5;
int field[width][height];
int altField[width][height];
int window[winWidth][winHeight];

int totalAdjacentSum(int wIndex, int hIndex, int array[width][height]);

void moveCurs(int a, int b){
 y += a;
 x += b;
 move(y,x);
}

void clrl(){
 moveCurs(0,-x);
 for(int i=0; i<200; i++)
  addch(' ');
 moveCurs(0,-x);
}

void generateField(bool treegen){
 for(int i=0; i<height; i++){
  for(int j=0; j<width; j++){
   int chance = rand() % range + 1;
   int cityChance = rand() % 10;
   int percent = 1;
   percent += totalAdjacentSum(j, i, altField) * multiplyer;
   if(chance <= percent)
    field[j][i]++;
   if(treegen){
    int treepercent = 1;
    int treechance = rand() % 500 + 1;
    if(treechance <= treepercent && field[j][i] > 7 && field[j][i] < 200)
     field[j][i] = 700;	
   }
   
   if(treegen){
	int cityPercent = 1;
	int cityChance = rand() % 10000 + 1;
	if(cityChance <= cityPercent && field[j][i] > 7 && field[j][i] < 200){
	 field[j][i] = 999;
	 field[j+1][i] = 999;
	 field[j-1][i] = 999;
	 field[j-1][i+1] = 999;
	 field[j-1][i-1] = 999;
	 field[j+1][i+1] = 999;
	 field[j+1][i-1] = 999;
	 field[j][i-1] = 999;
	 field[j][i+1] = 999;
    }
   }
  }
 }	
 for(int i=0; i<height; i++){
  for(int j=0; j<width; j++)
   altField[j][i] = field[j][i];
 }
}

int totalAdjacentSum(int wIndex, int hIndex, int array[width][height]){
 int sum = 0;
 if(wIndex-1 >= 0 && hIndex+1 <= height)
  sum += array[wIndex-1][hIndex+1];//top left
 if(hIndex+1 <= height)
  sum += array[wIndex][hIndex+1];//top
 if(wIndex+1 <= width && hIndex+1 <= height)
  sum += array[wIndex+1][hIndex+1];//top right
 if(wIndex-1 >= 0)	
  sum += array[wIndex-1][hIndex];//left
 if(wIndex+1 <= width)
  sum += array[wIndex+1][hIndex];//right
 if(wIndex-1 >= 0 && hIndex-1 >= 0)
  sum += array[wIndex-1][hIndex-1];//bottom left
 if(hIndex-1 >= 0)
  sum += array[wIndex][hIndex-1];//bottom
 if(wIndex+1 <= width && hIndex-1 >= 0)
  sum += array[wIndex+1][hIndex-1];//bottom right
 return sum;
}

/*void loadWindow(){
 int h = winY;
 for(int i=0; i<winHeight; i++, h++){
  int k = winX;
  for(int j=0; j<winWidth; j++, k++){
   window[j][i] = field[k][h]; 
  }
 }
}*/


void printField(){
 move(0,0);y=0;x=0;
 int h = winY;
 for(int i=0; i<winHeight; i++, h++){
  int k = winX;
  for(int j=0; j<winWidth; j++, k++){
   window[j][i] = field[k][h];
   if(window[j][i] >= 999){
    attron(COLOR_PAIR(9));
    printw("£");
   }else if(window[j][i] >= 700){
    attron(COLOR_PAIR(5));
    printw("T");
   }else if(window[j][i] > 90){
    attron(COLOR_PAIR(6));
    printw("^");
   }else if(window[j][i] > 60){
    attron(COLOR_PAIR(5));
    printw("^");
   }else if(window[j][i] > 7){
    attron(COLOR_PAIR(3));
    printw("#");
	//field[j][i] = 2;
   }else if(window[j][i] > 2){
    attron(COLOR_PAIR(2));
    printw("*");
	//field[j][i] = 1;
   }else{
    attron(COLOR_PAIR(4));
    printw("~");
	//field[j][i] = 0;
   }
    //refresh();
    attron(COLOR_PAIR(10));
    //refresh();	
 }

  moveCurs(1,0);
 }
 //moveCurs(-x/2,-y/2);
 //attron(COLOR_PAIR(7));
 //printw("@");
 refresh();
}

void zoomMap(int arrayToBeZoomed[width][height]){
 /*int zoomedMap[1000][1000];
 for(int i=0; i<1000; i+=10){
  for(int j=0; j<1000; j+=10){
   zoomedMap[(i/10)+5][(j/10)+5] = arrayToBeZoomed[i][j];
  }
 } 
 field = zoomedMap;*/
}

void Scroll(){
 curs_set(0);
 noecho();
 char ch;
 while(ch != 'p'){
  ch = getch();
  if(ch == 'a')
   winX -= scrollRate;
  if(ch == 'w')
   winY -= scrollRate;
  if(ch == 'd')
   winX += scrollRate;
  if(ch == 's')
   winY += scrollRate;
  if(ch == 'z')
   zoomMap(field); 
  if(winX < 0)
   winX = 0;
  if(winY < 0)
   winY = 0;
  if(winX > width-winWidth)
   winX = width-winWidth;
  if(winY > height-winHeight)
   winY = height-winHeight;
  printField();
  }
 curs_set(1);
 echo();
}

int main(){
 initscr();
 start_color();
 init_color(1,5,5,5);
 init_pair(1, 1, COLOR_BLACK);
 init_pair(2, COLOR_YELLOW, COLOR_YELLOW);
 init_pair(3, COLOR_GREEN, COLOR_GREEN);
 init_pair(4, COLOR_BLUE, COLOR_BLUE);
 init_pair(5, COLOR_CYAN, COLOR_CYAN);
 init_pair(6, COLOR_MAGENTA, COLOR_MAGENTA);
 init_pair(7, COLOR_RED, COLOR_BLACK);
 init_pair(8, COLOR_WHITE, COLOR_BLACK);
 init_pair(9, COLOR_WHITE, COLOR_BLACK);
 init_pair(10, COLOR_WHITE, COLOR_BLACK);
 refresh();

 srand(time(NULL));
 int run = 1;
 char input[3];

 while(run){
  move(winHeight+1,0);y=winHeight+1;x=0;
  printw( "Enter a command > ");
  getstr(input);		
  clrl();
  if(input[0] == 'g'){
   for(int i=0; i<height; i++){
    for(int j=0; j<width; j++){
     field[j][i] = 0;
     altField[j][i] = 0;
    }
   }
   printw("Times through the generator > ");
   getstr(input);
   genFactor = atoi(input);
   clrl();
   printw( "Intensity > ");
   getstr(input);
   multiplyer = atof(input);
   clrl();
   printw("Range > ");
   getstr(input);
   range = atoi(input);
   clrl();
   for(int i=0; i<genFactor; i++){
    if(i == genFactor-2)
	  generateField(true);
    else
      generateField(false);
   }
   printField();
   Scroll();
  }else if(input[0] == 'e'){
   run = 0;
  }else{
   printw("Invalid");
   getch();
   clrl();
  }
  refresh();
 }
 endwin();
 return 0;
}


