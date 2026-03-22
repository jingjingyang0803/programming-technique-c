/*
EXERCISE: Anagrams
Implement a program that checks if two strings are anagrams.

Example Output:
"arvo" ja "varo" ovat anagrammeja
"ilta" ja "talli" eivät ole anagrammeja
"elvis" ja "lives" ovat anagrammeja
"abababbbaabbaabb" ja "ababababbaabbaba" eivät ole anagrammeja
"bbaabaabababbaababab" ja "aabbaabbaabbaabbaabb" ovat anagrammeja
*/
#include "anagrammit.h"
#include <stdio.h>

int main() {

  char mj1[] = "abababbbaabbaabb";
  char mj2[] = "ababababbaabbaba";

  if (anagrammeja(mj1, mj2)) {
    printf("%s ja %s ovat anagrammeja\n", mj1, mj2);
  } else {
    printf("%s ja %s eivät ole anagrammeja\n", mj1, mj2);
  }

  return 0;
}