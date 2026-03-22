/*
EXERCISE: Caesar cipher

Prints the three strings orig, perm and mj on separate lines.
Calls caesarKoodaa(mj, orig, perm) and prints the now encrypted string mj.
Calls caesarKoodaa(mj, perm, orig) and prints the now decrypted string mj.
*/
#include "caesar.h"
#include <stdio.h>

int main() {
  char orig[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  char perm[] = "OIUGENYMSWXVALPKHBQCZDFJRT";
  char mj[] = "OHJELMOINNIN TEKNIIKKA";

  printf("%s\n", orig);
  printf("%s\n", perm);
  printf("%s\n", mj);

  caesarKoodaa(mj, orig, perm);
  printf("%s\n", mj);

  caesarKoodaa(mj, perm, orig);
  printf("%s\n", mj);

  return 0;
}