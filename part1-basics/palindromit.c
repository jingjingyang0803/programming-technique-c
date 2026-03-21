/*
EXERCISE: Palindromit
Implement a program that, for each command line parameter it receives, prints
whether the parameter in question is a palindrome or not.
Your implementation must be case-insensitive.
*/
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int is_palindrome(const char *str) {
  int left = 0;
  int right = strlen(str) - 1;

  while (left < right) {
    /* Compare characters case-insensitively */
    if (tolower((unsigned char)str[left]) !=
        tolower((unsigned char)str[right])) {
      return 0;
    }
    left++;
    right--;
  }
  return 1;
}

int main(int argc, char *argv[]) {
  int i;
  for (i = 1; i < argc; i++) {
    if (is_palindrome(argv[i])) {
      printf("\"%s\": on palindromi\n", argv[i]);
    } else {
      printf("\"%s\": ei ole palindromi\n", argv[i]);
    }
  }

  return 0;
}