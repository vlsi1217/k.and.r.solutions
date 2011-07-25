#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DELIMITER ' '
#define END_OF_STREAM -1
#define LINE_WIDTH 80
#define MAX_WORD_LENGTH 100
#define SPACE_WIDTH 1

int scan(char word[]);
int buffer(char word[]);

/*
 * Write a program to ``fold'' long input lines into two or more shorter lines
 * after the last non-blank character that occurs before the n-th column of
 * input. Make sure your program does something intelligent with very long
 * lines, and if there are no blanks or tabs before the specified column.
 *
 */

int main() {
  int remaining = LINE_WIDTH;
  char word[MAX_WORD_LENGTH];

  while((scan(word) > END_OF_STREAM)) {
    int width = strlen(word);

    if(width > remaining) {
      printf("\n");
      remaining = LINE_WIDTH - width;

    } else {
      remaining = remaining - width - SPACE_WIDTH;
    }

    printf("%s", word);
    printf(" ");
  }

  exit(EXIT_SUCCESS);
}

/* scanning state. waiting for beginning of word */

int scan(char word[]) {
  int character;

  while((character = getchar())) {
    if(character == EOF) {
      return END_OF_STREAM;
    }

    if(character != DELIMITER) {
      word[0] = character;
      return buffer(word);
    }
  }

  return -1;
}

/* buffering state. waiting for end of word */

int buffer(char word[]) {
  int character, index = 1;

  while((character = getchar())) {
    if(character != DELIMITER && character != EOF && index < MAX_WORD_LENGTH) {
      word[index] = character;

    } else {
      word[index] = '\0';
      return strlen(word);
    }

    index++;
  }

  return -1;
}

