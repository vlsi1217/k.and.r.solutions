#include <stdio.h>

#define MAXCHARS 200

int getline(char line[], int maxchars);
void copy(char to[], char from[]);

/*
 * Revise the main routine of the longest-line program so it will correctly
 * print the length of arbitrary long input lines, and as much as possible of
 * the text.
 *
 */

main() {
  int len;
  int max;
  char line[MAXCHARS];
  char longest[MAXCHARS];

  max = 0;
  while((len = getline(line, MAXCHARS)) > 0) {
    if (len > max) {
      max = len;
      copy(longest, line);
    }
  }

  if(max > 0) {
    printf("%s", longest);
  }

  return 0;
}

int getline(char line[], int maxchars) {
  int c, length, copied;

  copied = 0;

  for(length = 0; (c = getchar()) != EOF && c != '\0' && c != '\n'; length++) {
    if(copied < maxchars - 1) {
      line[copied++] = c;
    }
  }

  line[copied] = '\0';
  return length;
}

void copy(char to[], char from[]) {
  int i;

  i = 0;
  while((to[i] = from[i]) != '\0') {
    ++i;
  }
}
