#include <stdio.h>
#include <strings.h>
#include <stdlib.h>

/*
 * Write an alternative version of squeeze(s1,s2) that deletes each character
 * in s1 that matches any character in the string s2.
 *
 */

int getline2(char line[], int maxchars);
void squeeze(char input[], char blacklist[]);

#define MAX_LINE_LENGTH 1024

main(int argc, char *argv[]) {
  int length;
  char line[MAX_LINE_LENGTH];

  while((length = getline2(line, MAX_LINE_LENGTH)) >= 0) {
    squeeze(line, argv[1]);
    printf("%s\n", line);
  }

  exit(EXIT_SUCCESS);
}

void squeeze(char input[], char blacklist[]) {
  int i, j, k, banned;

  for(k = 0;  blacklist[k] != '\0'; k++) {
    banned = blacklist[k];

    for(i = j = 0; input[i] != '\0'; i++) {
      if(input[i] != banned) { input[j++] = input[i]; }
    }

    input[j] = '\0';
  }
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

