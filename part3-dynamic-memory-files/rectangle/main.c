#include "rectangle.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int i = 0;
  /* Declare and create a point object and four rectangle objects. */
  Point origin2 = {28, 17};
  Point origin4 = {23, 94};
  Rectangle *rect1 = createRectangle();
  Rectangle *rect2 = createRectangle2(origin2);
  Rectangle *rect3 = createRectangle3(50, 100);
  Rectangle *rect4 = createRectangle4(origin4, 100, 200);

  /* put the rectangles into an array to enable looping over them */
  Rectangle *rects[4];
  rects[0] = rect1;
  rects[1] = rect2;
  rects[2] = rect3;
  rects[3] = rect4;

  /* display width, height, area and position for the rectangles */
  for (i = 0; i < 4; ++i) {
    printf("Width of rect%d: %d\n", i + 1, rects[i]->width);
    printf("Height of rect%d: %d\n", i + 1, rects[i]->height);
    printf("Area of rect%d: %d\n", i + 1, getArea(rects[i]));
    printf("X Position of rect%d: %d\n", i + 1, rects[i]->origin.x);
    printf("Y Position of rect%d: %d\n", i + 1, rects[i]->origin.y);
  }

  /* set rect2's position */
  rect2->origin = origin4;

  /* display rect2's position */
  printf("X Position of rect2: %d\n", rect2->origin.x);
  printf("Y Position of rect2: %d\n", rect2->origin.y);

  /* move rect2 and display its new position */
  move(rect2, 40, 72);
  printf("X Position of rect2: %d\n", rect2->origin.x);
  printf("Y Position of rect2: %d\n", rect2->origin.y);

  /* free the dynamically allocated rectangles */
  for (i = 0; i < 4; ++i) {
    free(rects[i]);
  }
  return 0;
}
