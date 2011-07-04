#include <stdio.h>
#include <stdlib.h>

int lower(int c);

/*
 * Rewrite the function lower, which converts upper case letters to lower
 * case, with a conditional expression instead of if-else.
 *
 */

int main() {
  int character;

  while((character = getchar()) != '\0' && character != EOF) {
    printf("%c", lower(character));
  }

  exit(EXIT_SUCCESS);
}

/*
 * Convert c to lower case; ASCII only
 *
 */

int lower(int c) {
  return c >= 'A' && c <= 'Z' ? c + 'a' - 'A' : c;
}

