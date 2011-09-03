#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int getline2(char line[], int maxchars);
double atof2(char s[]);
double stof(char input[]);

#define MAX_LINE_LENGTH 1024

/*
 *  Extend atof to handle scientific notation of the form 123.45e-6 where
 *  a floating-point number may be followed by e or E and an optionally signed
 *  exponent.
 *
 */

int main() {
  char line[MAX_LINE_LENGTH + 1] = { 0 };
  double sum = 0.0;
  int length = 0;

  while((length = getline2(line, MAX_LINE_LENGTH)) >= 0) {
    printf("%1.2f\n", sum += stof(line));
  }

  exit(EXIT_SUCCESS);
}

/*
 *  Convert scientific string s to double
 *
 */

double stof(char input[]) {
  char base[MAX_LINE_LENGTH + 1] = { 0 };
  char exponent[MAX_LINE_LENGTH + 1] = { 0 };
  int input_i, base_i,  exponent_i;
  double parsed;

  // parse base

  input_i = 0;
  base_i = 0;

  while(input[input_i] != '\0' && input[input_i] != 'E' && input[input_i] != 'e' ) {
    base[base_i++] = input[input_i++];
  }

  parsed = atof2(base);

  // handle exponent

  exponent_i = 0;

  if(input[input_i] == 'e' || input[input_i] == 'E') {
    input_i++;

    if(input[input_i] == '+' || input[input_i] == '-') {
      while(input[input_i] != '\0' ) {
        exponent[exponent_i++] = input[input_i++];
      }

      // atoi will correctly parse sign; branching pushed into pow.

      parsed *= pow(10.0, atoi(exponent));
    }
  }

  return parsed;
}

/*
 *  Convert string s to double
 *
 */

double atof2(char input[]) {
  double val, power;
  int i, sign;

  // skip white space

  for(i = 0; isspace(input[i]); i++) {}

  sign = (input[i] == '-') ? -1 : 1;

  if(input[i] == '+' || input[i] == '-') {
    i++;
  }

  for(val = 0.0; isdigit(input[i]); i++) {
    val = 10.0 * val + (input[i] - '0');
  }

  if(input[i] == '.') {
    i++;
  }

  for(power = 1.0; isdigit(input[i]); i++) {
    val = 10.0 * val + (input[i] - '0');
    power *= 10;
  }

  return sign * val / power;
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

