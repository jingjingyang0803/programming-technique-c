#include "rectangle.h"
#include <stdlib.h>

/* Function to create a rectangle with default values. */
Rectangle *createRectangle(void) {
  Rectangle *rect =
      malloc(sizeof(Rectangle)); /* Allocate memory for a rectangle. */
  if (rect != NULL) {
    rect->width = 0;    /* Set default width. */
    rect->height = 0;   /* Set default height. */
    rect->origin.x = 0; /* Set default x position. */
    rect->origin.y = 0; /* Set default y position. */
  }
  return rect; /* Return the created rectangle. */
}

/* Function to create a rectangle with a specified origin. */
Rectangle *createRectangle2(Point origin) {
  Rectangle *rect =
      malloc(sizeof(Rectangle)); /* Allocate memory for a rectangle. */
  if (rect != NULL) {
    rect->width = 0;       /* Set default width. */
    rect->height = 0;      /* Set default height. */
    rect->origin = origin; /* Set the specified origin. */
  }
  return rect; /* Return the created rectangle. */
}

/* Function to create a rectangle with specified width and height. */
Rectangle *createRectangle3(int width, int height) {
  Rectangle *rect =
      malloc(sizeof(Rectangle)); /* Allocate memory for a rectangle. */
  if (rect != NULL) {
    rect->width = width;   /* Set the specified width. */
    rect->height = height; /* Set the specified height. */
    rect->origin.x = 0;    /* Set default x position. */
    rect->origin.y = 0;    /* Set default y position. */
  }
  return rect; /* Return the created rectangle. */
}

/* Function to create a rectangle with specified origin, width, and height. */
Rectangle *createRectangle4(Point origin, int width, int height) {
  Rectangle *rect =
      malloc(sizeof(Rectangle)); /* Allocate memory for a rectangle. */
  if (rect != NULL) {
    rect->width = width;   /* Set the specified width. */
    rect->height = height; /* Set the specified height. */
    rect->origin = origin; /* Set the specified origin. */
  }
  return rect; /* Return the created rectangle. */
}

/* Function to calculate the area of a rectangle. */
int getArea(const Rectangle *r) {
  return r->width * r->height; /* Return the area (width * height). */
}

/* Function to move a rectangle to a specified position in the x and y
 * directions.
 */
void move(Rectangle *rect, int x, int y) {
  rect->origin.x = x; /* Move the rectangle to the specified x position. */
  rect->origin.y = y; /* Move the rectangle to the specified y position. */
}
