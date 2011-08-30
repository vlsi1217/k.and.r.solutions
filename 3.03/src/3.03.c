#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void expand(char line[], char expanded[]);
int expansion(char left, char right, char fill[]);

#define MAX_IN 1024 * 512
#define MAX_OUT MAX_IN * 3
#define ENUM_MAX 26
#define ENUMS 6

int main() {
  char line[MAX_IN + 1] = { 0 };
  char expanded[MAX_OUT + 1] = { 0 };
  int read = 0, lcur = 0;

  while((read = getchar())) {
    if(read == '\n' || read == EOF || lcur == MAX_IN) {
      line[lcur] = '\0';
      expand(line, expanded);
      printf("%s\n", expanded);
      lcur = 0;
    } else if(lcur < MAX_IN) {
      line[lcur++] = read;
    }

    if(read == EOF) { break; }
  }

  exit(EXIT_SUCCESS);
}

void expand(char line[], char expanded[]) {
  char fill[ENUM_MAX + 1] = { 0 };
  int lcur, ecur, fcur, filled;

  ecur = 0;
  lcur = 0;

  while(line[lcur] != '\0' && lcur < MAX_IN) {
    if(line[lcur] == '-' && lcur > 0) {
      filled = expansion(expanded[ecur - 1], line[lcur + 1], fill);

      if(filled > 0) {
        fcur = 0;
        ecur--;

        while(fcur < filled && ecur < MAX_OUT) {
          expanded[ecur++] = fill[fcur++];
        }

        lcur++; // move past expression

      } else {
        expanded[ecur++] = line[lcur];
      }

    } else {
      expanded[ecur++] = line[lcur];
    }

    lcur++;
  }

  expanded[ecur] = '\0';
}

int expansion(char left, char right, char fill[]) {
  int set, length, scur, fcur;
  int opened;

  char table[ENUMS][ENUM_MAX + 1] = {
    "abcdefghijklmnopqrstuvwxyz",
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ",
    "zyxwvutsrqponmlkjihgfedcba",
    "ZYXWVUTSRQPONMLKJIHGFEDCBA",
    "0123456789",
    "9876543210"
  };

  for(set = 0; set < ENUMS; set++) {
    length = strlen(table[set]);
    opened = 0;
    fcur = 0;

    for(scur = 0; scur < length; scur++) {
      if(left == table[set][scur]) {
        opened = 1;
      }

      if(opened) {
        fill[fcur++] = table[set][scur];

        if(right == table[set][scur]) {
          return fcur;
        }
      }
    }
  }

  return -1;
}

