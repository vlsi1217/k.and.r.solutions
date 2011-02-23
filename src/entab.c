#include <stdio.h>

#define TAB 9

main() {
  int c;

  while((c = getchar()) != EOF) {
    if(c == TAB) {
      printf("  ");
    }  else {
      printf("%c", c);
    }
  }
}
