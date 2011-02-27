#include <stdio.h>

#define TAB 9
#define TABWIDTH 2

void print_buffer(char buffer[]);

main() {
  int i, character;
  char buffer[TABWIDTH];

  while((character = getchar()) != EOF) {
    for(i = 0; i < TABWIDTH; i++) {
      buffer[i] = character;
    }

    print_buffer(buffer);
  }
}

void print_buffer(char buffer[]) {
  if(buffer[0] == ' ') {
    if(buffer[1] == ' ') {
      printf("%c", TAB);
    } else {
      printf("%s", buffer);
    }
  }
}
