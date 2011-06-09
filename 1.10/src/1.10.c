#include <stdio.h>

#define BACKSLASH '\\'
#define BACKSPACE '\b'
#define TAB '\t'

/*
 * Write a program to copy its input to its output, replacing each tab by \t,
 * each backspace by \b, and each backslash by \\. This makes tabs and
 * backspaces visible in an unambiguous way.
 *
 */

int main() {
  int c;

  while((c = getchar()) != EOF) {
    if(c == BACKSLASH) {
      printf("\\\\");

    } else if(c == BACKSPACE) {
      printf("\\b");

    } else if(c == TAB) {
      printf("\\t");

    } else {
      putchar(c);
    }
  }
}

