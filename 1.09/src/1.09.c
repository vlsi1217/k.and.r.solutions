#include <stdio.h>

#define BLANK ' '

int main() {
  int c, last;

  while((c = getchar()) != EOF) {
    if(c != BLANK || last != BLANK) {
      putchar(c);
    }

    last = c;
  }
}
