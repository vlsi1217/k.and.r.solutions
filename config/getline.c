#include <stdio.h>
#include <stdlib.h>

int getline2(char line[], int maxchars);

#define MAX_LINE_LENGTH 256

int main() {
  int length = 0;
  char line[MAX_LINE_LENGTH];

  while((length = getline2(line, MAX_LINE_LENGTH)) >= 0) {
    printf("%s\n", line);
  }

  exit(EXIT_SUCCESS);
}

/*
 * getline implementation from chapter 1.
 *
 */

int getline2(char line[], int maxchars) {
  int c, length, copied;
  copied = 0;

  for(length = 0; (c = getchar()) != EOF && c != '\0' && c != '\n'; length++) {
    if(copied < maxchars - 1) {
      line[copied++] = c;
    }
  }

  line[copied] = '\0';

  if(c == EOF && length == 0) {
    return -1;
  } else {
    return length;
  }
}

