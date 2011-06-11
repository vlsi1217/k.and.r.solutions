#include <stdio.h>

int getline(char line[], int maxchars);

#define LINE_BUFFER 1000
#define TRUNCATE 80

/*
 * Write a program to print all input lines that are longer than 80
 * characters.
 *
 */

main() {
  int length;
  char line[LINE_BUFFER];

  length = 0;

  while((length = getline(line, LINE_BUFFER)) > 0) {
    if(length > TRUNCATE) {
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

