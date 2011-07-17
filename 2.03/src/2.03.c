#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Write a function htoi(s), which converts a string of hexadecimal digits
 * (including an optional 0x or 0X) into its equivalent integer value. The
 * allowable digits are 0 through 9, a through f, and A through F.
 *
 */

int getline2(char line[], int maxchars);
int htoi(char input[]);
int normalize(char input[]);

#define MAX_LINE_LENGTH 80

int main() {
  int length;
  char line[MAX_LINE_LENGTH];

  length = 0;

  while((length = getline2(line, MAX_LINE_LENGTH)) >= 0) {
    if(normalize(line)) {
      printf("%i\n", htoi(line));

    } else {
      printf("invalid input: '%s'\n", line);
      exit(EXIT_FAILURE);

    }
  }

  exit(EXIT_SUCCESS);
}

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

int normalize(char input[]) {
  int i, chr;

  for(i = 0; i < strlen(input); i++) {
    chr = input[i];

    // delete x or X from the end of the string if present.

    if(i == strlen(input) - 1 && (chr == 'X' || chr == 'x')) {
      input[i] = '\0';


    } else if(!isxdigit(chr)) {
      return 0;

    } else {
      input[i] = tolower(chr);

    }
  }

  return 1;
}

int htoi(char input[]) {
  int i, chr;
  int num = 0;

  for(i = 0; i < strlen(input); i++) {
    chr = input[i];

    if(isdigit(chr)) {
      num += 15 * num + chr - '0';

    } else {
      num += 15 * num + chr - 'a' + 10;

    }
  }

  return num;
}

