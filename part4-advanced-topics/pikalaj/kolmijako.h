#ifndef KOLMIJAKO_H
#define KOLMIJAKO_H

typedef struct {
  int x;
  int y;
} IntPari;

IntPari kolmijako(unsigned int koko, int taulu[], int vipu1, int vipu2, int *p1,
                  int *p2);

#endif
