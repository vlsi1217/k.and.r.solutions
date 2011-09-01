#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

int getline2(char line[], int maxchars);
void itoa(int n, char s[]);
void reverse(char s[]);

#define MAX_LINE_LENGTH 256

/*
 * In a two's complement number representation, our version of itoa does not
 * handle the largest negative number, that is, the value of n equal to

 *   -(2 ** wordsize - 1)
 *
 * Explain why not. Modify it to print that value correctly, regardless of the
 * machine on which it runs.
 *
 * Explanation
 * -----------
 *
 * Twos complement uses a leading 1 bit to represent negative numbers. Since
 * it represents 0 as 0x1, the shifted range of positive numbers is one
 * smaller than the range of negative numbers.
 *
 * iotas original sign handling does not account for this.
 *
 */

int main() {
  char line[MAX_LINE_LENGTH];
  int length = 0;
  long input = 0;

  while((length = getline2(line, MAX_LINE_LENGTH)) >= 0) {
    input = atoi(line);
    itoa(input, line);
    printf("%s\n", line);
  }

  exit(EXIT_SUCCESS);
}

void itoa(int n, char s[]) {
  int i, sign;

  sign = n < 0 ? -1 : 1;
  i = 0;

  do {
    s[i++] = sign * (n % 10) + '0';

  } while((n /= 10) != 0);

  if(sign == -1) {
    s[i++] = '-';
  }

  s[i] = '\0';

  reverse(s);
}

void reverse(char input[]) {
  int length = strlen(input);
  int i, other;
  char c;

  for(i = 0; i < length / 2; i++) {
    other =  length - i - 1;
    c = input[i];
    input[i] = input[other];
    input[other] = c;
  }
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

