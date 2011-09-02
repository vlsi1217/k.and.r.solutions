#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>

int getline2(char line[], int maxchars);
void itob(int n, char line[], int base);
void reverse(char s[]);
void table(char output[]);

#define MAX_LINE_LENGTH 1024
#define LETTERS 26
#define NUMBERS 10
#define GLYPHS LETTERS + NUMBERS

/*
 * Write the function itob(n, s, b) that converts the integer n into a base
 * b character representation in the string s. In particular, itob(n, s, 16)
 * formats s as a hexadecimal integer in s.
 *
 */

int main(int argc, char *argv[]) {
  char line[MAX_LINE_LENGTH + 1] = { 0 };
  int length = 0, input = 0, base = 16, opt = -1;

  // parse command-line

  while((opt = getopt(argc, argv, "b:")) != -1) {
    switch(opt) {
    case 'b':
      base = atoi(optarg);
      break;
    default:
      fprintf(stderr, "Usage: %s [-b base]\n", argv[0]);
      exit(EXIT_FAILURE);
    }
  }

  while((length = getline2(line, MAX_LINE_LENGTH)) >= 0) {
    input = atoi(line);
    itob(input, line, base);
    printf("%s\n", line);
  }

  exit(EXIT_SUCCESS);
}

/*
 *  Convert a given base 10 `n` into a base `base` represented in the string
 *  array `output`.
 *
 */

void itob(int n, char output[], int base) {
  char glyphs[GLYPHS + 1] = { 0 };
  int sign = n < 0 ? -1 : 1;
  int i_output = 0;
  int index = 0;

  table(glyphs);

  while(sign * n > 0) {
    index = (sign * n) - ((n / base) * base * sign);
    output[i_output++] = glyphs[index];

    n /= base;
  }

  if(sign < 0) {
    output[i_output++] = '-';
  }

  output[i_output] = '\0';
  reverse(output);
}

/*
 *  Generates an array of glyphs.
 *
 */

void table(char output[]) {
  int glyph = 0, letter = 0, number = 0;

  for(number = 0; number < NUMBERS; number++) {
    output[glyph++] = number + '0';
  }

  for(letter = 0; letter < LETTERS; letter++) {
    output[glyph++] = letter + 'a';
  }
}

/*
 *  Reverses the input array.
 *
 */

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

