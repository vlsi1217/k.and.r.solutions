#include <stdio.h>

int getline(char line[], int maxchars);
int reverse(char line[], int length);

#define MAX_LINE_LENGTH 80

int main() {
  int length;
  char line[MAX_LINE_LENGTH];

  length = 0;

  while((length = getline(line, MAX_LINE_LENGTH)) >= 0) {
    reverse(line, length);
    printf("%s", line);
    printf("\n");
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

  if(c == EOF && length == 0) {
    return -1;
  } else {
    return length;
  }
}

int reverse(char line[], int length) {
  int i, pair;
  char c;

  for(i = 0; i < length / 2; i++) {
    pair = length - 1 - i;

    c = line[pair];
    line[pair] = line[i];
    line[i] = c;
  }
}

