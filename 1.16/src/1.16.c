#include <stdio.h>

#define MAXLINE 200

int getline(char line[], int maxline);
void copy(char to[], char from[]);

main() {
  int len;
  int max;
  char line[MAXLINE];
  char longest[MAXLINE];

  max = 0;
  while((len = getline(line, MAXLINE)) > 0) {
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

int getline(char s[], int lim) {
  int c, i, length;

  i = 0;
  length = 0;

  while((c = getchar()) != EOF && c != '\n') {
    if(i < lim - 2) {
      s[i] = c;
      ++i;
    }

    length++;
  }

  if (c == '\n') {
    s[i] = c;
    ++i;

    length++;
  }

  s[i] = '\0';
  return length;
}

void copy(char to[], char from[]) {
  int i;

  i = 0;
  while((to[i] = from[i]) != '\0') {
    ++i;
  }
}
