#include "field.h"
#include "tile.h"
#include <iostream>
#define lWidth 1000
#define lHeight 1000 
#define mWidth 600
#define mHeight 600
#define sWidth 200
#define sHeight 200

void field::generate(int width, int height){
 for(int k=0; k<iterations; k++){
  for(int i=0; i<height; i++){
   for(int j=0; j<width; j++){
    int chance = rand() % range + 1;
    int percent = 1;
    int sum = 0;
    if(j-1 >= 0 && i+1 <= height)
     sum += altNumericTerrain[j-1][i+1];//top left
    if(i+1 <= height)
     sum += altNumericTerrain[j][i+1];//top
    if(j+1 <= width && i+1 <= height)
     sum += altNumericTerrain[j+1][i+1];//top right
    if(j-1 >= 0)
     sum += altNumericTerrain[j-1][i];//left
    if(j+1 <= width)
     sum += altNumericTerrain[j+1][i];//right
    if(j-1 >= 0 && i-1 >= 0)
     sum += altNumericTerrain[j-1][i-1];//bottom left
    if(i-1 >= 0)
     sum += altNumericTerrain[j][i-1];//bottom
    if(j+1 <= width && i-1 >= 0)
     sum += altNumericTerrain[j+1][i-1];//bottom right
    percent += sum * intensity;
    if(chance <= percent)
     numericTerrain[j][i]++;
   }
  }
 }
}

smallField::smallField(int iter, int ran, int inte){
 int width = sWidth;
 int height = sHeight; 
 generate(sWidth, sHeight);
}

mediumField::mediumField(int iter, int ran, int inte){
 int width = mWidth;
 int height = mHeight;
 generate(mWidth, mHeight);
}

largeField::largeField(int iter, int ran, int inte){
 int width = lWidth;
 int height = lHeight;
 generate(lWidth, lHeight);
}

field::field(int iter, int ran, int inte){
 iterations = iter;
 range = ran;
 intensity = inte;
}
