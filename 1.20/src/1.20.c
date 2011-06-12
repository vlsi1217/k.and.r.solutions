#include <stdio.h>

#define TAB 9
#define TABSTOP 4

/*
 *  Write a program detab that replaces tabs in the input with the proper
 *  number of blanks to space to the next tab stop. Assume a fixed set of tab
 *  stops, say every n columns. Should n be a variable or a symbolic
 *  parameter?
 *
 */

main() {
  int cursor = 1;
  int expansion = 0;
  int i, c;

  while((c = getchar()) != EOF) {
    if(c == TAB) {
      expansion = TABSTOP - ((cursor - 1) % TABSTOP) - 1;

      for(i = 0; i <= expansion; i++) {
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

  return 0;
}

