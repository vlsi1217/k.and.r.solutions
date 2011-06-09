#include <stdio.h>

#define TAB 9
#define TABSTOP 2

/*
 *  Write a program detab that replaces tabs in the input with the proper
 *  number of blanks to space to the next tab stop. Assume a fixed set of tab
 *  stops, say every n columns. Should n be a variable or a symbolic
 *  parameter.
 *
 */

main() {
  int c;
  int cursor = 0;

  while((c = getchar()) != EOF) {
    int stopped = cursor % TABSTOP;

    if(c == TAB) {
      if(stopped == 0) {
        printf("  ");
        cursor += 2;
      } else {
        printf(" ");
        cursor++;
      }
    } else {
      if(c == '\n') {
        cursor = 0;
      } else {
        cursor++;
      }

      printf("%c", c);
    }
  }
}
