#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <getopt.h>

int getline2(char line[], int maxchars);
void itoa(int n, char s[], int width);
void reverse(char s[]);

#define MAX_LINE_LENGTH 256

/*
 * Write a version of itoa that accepts three arguments instead of two. The
 * third argument is a minimum field width; the converted number must be
 * padded with blanks on the left if necessary to make it wide enough.
 *
 */

int main(int argc, char* argv[]) {
  char line[MAX_LINE_LENGTH];
  int length = 0;
  int width = 0;
  int opt = -1;
  long input = 0;

  // parse command-line

  while((opt = getopt(argc, argv, "w:")) != -1) {
    switch(opt) {
    case 'w':
      width = atoi(optarg);
      break;
    default:
      fprintf(stderr, "Usage: %s [-w min_width]\n", argv[0]);
      exit(EXIT_FAILURE);
    }
  }

  while((length = getline2(line, MAX_LINE_LENGTH)) >= 0) {
    input = atoi(line);
    itoa(input, line, width);
    printf("%s\n", line);
  }

  exit(EXIT_SUCCESS);
}

void itoa(int n, char s[], int width) {
  int i, j, sign;

  sign = n < 0 ? -1 : 1;
  i = 0;

  do {
    s[i++] = sign * (n % 10) + '0';

  } while((n /= 10) != 0);

  if(sign == -1) {
    s[i++] = '-';
  }

  // padding

  for(j = i; j < width; j++) {
    s[j] = ' ';
  }

  s[j] = '\0';
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

