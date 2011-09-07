#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getch(void);
void ungetch(int);

// buffer for ungetch

char last = '\0';

/*
 * Suppose that there will never be more than one character of pushback.
 * Modify getch and ungetch accordingly.
 *
 */

int main() {
  int c;

  while((c = getch()) != EOF) {
    ungetch(c);
    putchar(getch());
  }
}

/*
 * Get a (possibly pushed-back) character
 *
 */

int getch(void) {
  int ret;

  if(last == '\0') {
    ret = getchar();
  } else {
    ret = last;
    last = '\0';
    return ret;
  }

  return ret;
}

/*
 * Push character back on input
 *
 */

void ungetch(int c) {
  if(last != '\0') {
    printf("ungetch: too many characters\n");
  } else {
    last = c;
  }
}

