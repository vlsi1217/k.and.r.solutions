#include <stdio.h>

#define TAB 9
#define TABSTOP 2

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
