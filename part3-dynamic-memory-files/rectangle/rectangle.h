/*
EXERCISE: Dynamically created objects
*/
#ifndef RECTANGLE_H
#define RECTANGLE_H

/* Define a structure to represent a point in 2D space. */
typedef struct {
  int x; /* The x-coordinate of the point. */
  int y; /* The y-coordinate of the point. */
} Point;

/* Define a structure to represent a rectangle, which includes its width,
   height, and the position of its origin (a Point). */
typedef struct {
  int width;    /* The width of the rectangle. */
  int height;   /* The height of the rectangle. */
  Point origin; /* The position of the rectangle's origin. */
} Rectangle;

/***************** Function prototypes for rectangle operations
 * *****************/
/* Function prototype for creating a rectangle with default values. */
Rectangle *createRectangle(void);

/* Function prototype for creating a rectangle with a specified origin. */
Rectangle *createRectangle2(Point origin);

/* Function prototype for creating a rectangle with specified width and height.
 */
Rectangle *createRectangle3(int width, int height);

/* Function prototype for creating a rectangle with specified origin, width, and
 * height. */
Rectangle *createRectangle4(Point origin, int width, int height);

/* Function prototype for calculating the area of a rectangle. */
int getArea(const Rectangle *r);

/* Function prototype for moving a rectangle by specified amounts in the x and y
 * directions. */
void move(Rectangle *rect, int x, int y);

#endif /* RECTANGLE_H */
