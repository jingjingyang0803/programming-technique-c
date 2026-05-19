#include "vertailu.h"
#include "rectangle.h"
#include <string.h>

int rectAlaVrt(const void *a, const void *b) {
  const struct Rectangle *r1;
  const struct Rectangle *r2;
  int ala1;
  int ala2;

  r1 = *(const struct Rectangle *const *)a;
  r2 = *(const struct Rectangle *const *)b;

  ala1 = r1->width * r1->height;
  ala2 = r2->width * r2->height;

  if (ala1 < ala2) {
    return -1;
  }
  if (ala1 > ala2) {
    return 1;
  }

  return 0;
}

int rectXyVrt(const void *a, const void *b) {
  const struct Rectangle *r1;
  const struct Rectangle *r2;

  r1 = *(const struct Rectangle *const *)a;
  r2 = *(const struct Rectangle *const *)b;

  if (r1->origin.x < r2->origin.x) {
    return -1;
  }
  if (r1->origin.x > r2->origin.x) {
    return 1;
  }

  if (r1->origin.y < r2->origin.y) {
    return -1;
  }
  if (r1->origin.y > r2->origin.y) {
    return 1;
  }

  return 0;
}

int rectLeveysVrt(const void *a, const void *b) {
  const struct Rectangle *r1;
  const struct Rectangle *r2;

  r1 = *(const struct Rectangle *const *)a;
  r2 = *(const struct Rectangle *const *)b;

  if (r1->width > r2->width) {
    return -1;
  }
  if (r1->width < r2->width) {
    return 1;
  }

  return 0;
}

int mjPitAakkosVrt(const void *a, const void *b) {
  const char *s1;
  const char *s2;
  size_t len1;
  size_t len2;

  s1 = *(const char *const *)a;
  s2 = *(const char *const *)b;

  len1 = strlen(s1);
  len2 = strlen(s2);

  if (len1 > len2) {
    return -1;
  }
  if (len1 < len2) {
    return 1;
  }

  return strcmp(s1, s2);
}
