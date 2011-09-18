#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getline2(char line[], int maxchars);
void reverse(char input[], int offset);

#define MAX_LINE_LENGTH 256

/*
 * Write a recursive version of the function reverse(s), which reverses the
 * string s in place.
 *
 */

int main() {
  char line[MAX_LINE_LENGTH + 1] = { 0 };
  int length = 0;

  while((length = getline2(line, MAX_LINE_LENGTH)) >= 0) {
    reverse(line, 0);
    printf("%s\n", line);
  }

  exit(EXIT_SUCCESS);
}

/*
 * A somewhat construed recursive reversal function.
 *
 */

void reverse(char input[], int offset) {
  int length = strlen(input);
  int mirror = length - offset - 1;
  char tmp;

  if(offset < length / 2) {
    reverse(input, offset + 1);
  }

  tmp = input[offset];
  input[offset] = input[mirror];
  input[mirror] = tmp;
}

/*
 * getline implementation from chapter 1.
 *
 */

int getline2(char line[], int maxchars) {
  int c, length, copied;
  copied = 0;

  for(length = 0; (c = getchar()) != EOF && c != '\0' && c != '\n'; length++) {
    if(copied < maxchars) {
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

