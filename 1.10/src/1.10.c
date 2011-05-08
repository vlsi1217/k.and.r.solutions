#include <stdio.h>

#define BACKSLASH '\\'
#define BACKSPACE '\b'
#define TAB '\t'

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
