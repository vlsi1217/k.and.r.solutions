#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DELIMITER ' '
#define END_OF_STREAM -1
#define MAX_WORD_LENGTH 100

/*
 * Write a program that prints its input one word per line.
 *
 */

int main() {
  char word[MAX_WORD_LENGTH];

  while(scan(word) > END_OF_STREAM) {
    printf("%s", word);
    printf("\n");
  }

  exit(EXIT_SUCCESS);
}

/* scanning state. waiting for beginning of word */

int scan(char word[]) {
  int character;

  while(character = getchar()) {
    if(character == EOF) {
      return END_OF_STREAM;
    }

    if(character != DELIMITER) {
      word[0] = character;
      return buffer(word);
    }
  }
}

/* buffering state. waiting for end of word */

int buffer(char word[]) {
  int character, index = 1;

  while(character = getchar()) {
    if(character != DELIMITER && character != EOF && index < MAX_WORD_LENGTH) {
      word[index] = character;

    } else {
      word[index] = '\0';
      return strlen(word);
    }

    index++;
  }
}
