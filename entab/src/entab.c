#include <stdio.h>
#include <stdlib.h>

#define TAB 9
#define TABWIDTH 2

void print_buffer(char buffer[]);

int main() {
  int character, i = 0;
  char buffer[TABWIDTH];

  while((character = getchar()) != EOF) {
    buffer[i] = character;

    if(i == TABWIDTH - 1) {
      print_buffer(buffer);
      i = 0;
    } else if(character == '\n') {
      printf("\n");
      i = 0;
    } else {
      i++;
    }
  }

  return EXIT_SUCCESS;
}

void print_buffer(char buffer[]) {
  if(buffer[0] == ' ' && buffer[1] == ' ') {
    printf("%c", TAB);
  } else {
    printf("%s", buffer);
  }
}
