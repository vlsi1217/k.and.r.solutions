#include <stdio.h>

int getline(char line[], int maxchars);

#define MAX_LINE_LENGTH 80

/*
 * Write a program to print all input lines that are longer than 80
 * characters.
 *
 */

main() {
  int length;
  char line[MAX_LINE_LENGTH];

  length = 0;

  while((length = getline(line, MAX_LINE_LENGTH)) > 0) {
    if(length >= MAX_LINE_LENGTH) {
      printf("%s", line);
    }
  }

  return 0;
}

int getline(char line[], int maxchars) {
  int c, length, copied;
  copied = 0;

  for(length = 0; (c = getchar()) != EOF && c != '\0' && c != '\n'; length++) {
    if(copied < maxchars - 1) {
      line[copied++] = c;
    }
  }

  line[copied] = '\0';
  return length;
}
