#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int getline2(char line[], int maxchars);
int isnumerical(char string[]);
unsigned rightrot(unsigned x, int n);
void usage();

#define MAX_LINE_LENGTH 256
#define INT_WIDTH 32

/*
 * Write a function rightrot(x,n) that returns the value of the integer
 * x rotated to the right by n positions.
 *
 * Note: this means rotating on a 32 bit unsigned int ring.
 * Note: Added some validations to this one.
 *
 */

int main(int argc, char *argv[]) {
  int length = 0;
  char line[MAX_LINE_LENGTH];
  int distance;

  if(argc != 2 || !isnumerical(argv[1])) {
    usage();
    exit(EXIT_FAILURE);

  } else {
    distance = atoi(argv[1]);

  }

  while((length = getline2(line, MAX_LINE_LENGTH)) >= 0) {
    if(isnumerical(line)) {
      printf("%u\n", rightrot(atoi(line), distance));

    } else {
      exit(EXIT_FAILURE);

    }
  }

  exit(EXIT_SUCCESS);
}

/*
 * Returns x rotated to the right by n positions on the ring.
 *
 */

unsigned rightrot(unsigned x, int n) {
  return x >> n | x << (INT_WIDTH - n);
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

/*
 * Determines if an input string is \d*.
 *
 */

int isnumerical(char string[]) {
  int i;

  for(i = 0; string[i] != '\0'; i++) {
    if(!isdigit(string[i])) {
      return 0;
    }
  }

  return 1;
}

/*
 * Print the correct usage.
 *
 */

void usage() {
  printf("usage: 2.07 \\d*\n");
}

