#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

int getline2(char line[], int maxchars);
int iota2(int n, char output[]);

#define MAX_LINE_LENGTH 256

/*
 * Adapt the ideas of printd to write a recursive version of itoa; that is,
 * convert an integer into a string by calling a recursive routine.
 *
 */

int main() {
  char line[MAX_LINE_LENGTH + 1] = { 0 };
  char output[MAX_LINE_LENGTH + 1] = { 0 };
  int length = 0;

  while((length = getline2(line, MAX_LINE_LENGTH)) >= 0) {
    iota2(atoi(line), output);
    printf("%s\n", output);
  }

  exit(EXIT_SUCCESS);
}


int iota2(int n, char output[]) {
  int pointer = 0;

  if(n < 0) {
    putchar('-');
    n = -n;
  }

  if(n / 10) {
    pointer = iota2(n / 10, output);
  }

  output[pointer++] = n % 10 + '0';
  output[pointer] = '\0';

  return pointer;
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

