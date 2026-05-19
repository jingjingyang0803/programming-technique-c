#ifndef RECTANGLE_H
#define RECTANGLE_H

struct Point {
  int x;
  int y;
};

typedef struct Point Point;

struct Rectangle {
  Point origin;
  int width;
  int height;
};

typedef struct Rectangle Rectangle;

#endif
