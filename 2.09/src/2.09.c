#include <stdio.h>
#include <stdlib.h>

int bitcount(unsigned x);
int getline2(char line[], int maxchars);

#define MAX_LINE_LENGTH 256

/*
 * In a two's complement number system, x &= (x-1) deletes the rightmost 1-bit
 * in x. Explain why. Use this observation to write a faster version of
 * bitcount.
 *
 */

int main() {
  int length = 0;
  char line[MAX_LINE_LENGTH];

  while((length = getline2(line, MAX_LINE_LENGTH)) >= 0) {
    printf("%i\n", bitcount(atoi(line)));
  }

  exit(EXIT_SUCCESS);
}

/*
 * Subtracting 1 from 1 << n (a 1 followed by trailing 0s) will cause the
 * number to become 2**n - 1 (all 1's, shifted to the right one position).
 * This is the exact bitmask which will unset the rightmost 1-bit when &ing.
 * Since &ing a number with itself yields itself, the more significant bits
 * remain the untouched.
 *
 */

int bitcount(unsigned x) {
  int b;

  for(b = 0; x != 0; x &= x - 1) { b++; }

  return b;
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

