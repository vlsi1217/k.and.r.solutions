#include <stdio.h>

#define BLANK ' '

/*
 * Write a program to copy its input to its output, replacing each string of
 * one or more blanks by a single blank.
 *
 */

int main() {
  int c, last;

  while((c = getchar()) != EOF) {
    if(c != BLANK || last != BLANK) {
      putchar(c);
    }

    last = c;
  }
}
