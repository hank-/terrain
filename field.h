#ifndef FIELD_H
#define FIELD_H
#include "tile.h"
#define lWidth 1000
#define lHeight 1000 
#define mWidth 600
#define mHeight 600
#define sWidth 200
#define sHeight 200

class field{
 public:
  field(int iter, int ran, int inte);
  void generate(int width, int height);
 protected: 
  int iterations;
  int range;
  int intensity;
};

class smallField : public field{
 public:
  smallField(int iter, int ran, int inte)
  : field(iter, ran, inte);
 private:
  int numericTerrain[sWidth][sHeight];
  int altNumericTerrain[sWidth][sHeight];
  tile terrain[sWidth][sHeight];
};

class mediumField : public field{
 public:
  mediumField(int iter, int ran, int inte)
  : field(iter, ran, inte);
 private:
  int numericTerrain[mWidth][mHeight];
  int altNumericTerrain[mWidth][mHeight];
  tile terrain[mWidth][mHeight];
};

class largeField : public field{
 public:
  largeField(int iter, int ran, int inte)
  : field(iter, ran, inte);
 private:
  int numericTerrain[lWidth][lHeight];
  int altNumericTerrain[lWidth][lHeight];
  tile terrain[lWidth][lHeight];
};

#endif
