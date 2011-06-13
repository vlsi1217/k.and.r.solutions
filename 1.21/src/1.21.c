#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAB 9
#define TABWIDTH 4

void flush(int spaces, int column);

/*
 * Write a program entab that replaces strings of blanks by the minimum number
 * of tabs and blanks to achieve the same spacing. Use the same tab stops as
 * for detab. When either a tab or a single blank would suffice to reach a tab
 * stop, which should be given preference?
 *
 */

int main() {
  int character = 0;
  int column = 0, spaces = 0;

  while((character = getchar()) != EOF) {
    if(character == ' ') {
      spaces++;

    } else {
      flush(spaces, column);
      putchar(character);
      spaces = 0;
    }

    if(character == '\n') {
      column = 0;
    } else {
      column++;
    }
  }

  return EXIT_SUCCESS;
}

void flush(int spaces, int column) {
  int i = 0;
  int overhang = spaces - (column % TABWIDTH);

  while(i < spaces) {
    if(i < overhang) {
      putchar('\t');
      i += TABWIDTH; // XXX too much

    } else {
      putchar(' ');
      i++;

    }
  }
}

