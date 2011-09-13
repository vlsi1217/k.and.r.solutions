#include <stdio.h>
#include <stdlib.h>
#include "getch.h"

#define BUFSIZE 100

char buf[BUFSIZE];    // buffer for ungetch
int bufp = 0;         // next free position in buf

/*
 * Get a (possibly pushed-back) character
 *
 */

int getch(void) {
  return (bufp > 0) ? buf[--bufp] : getchar();
}

/*
 * Push character back on input
 *
 */

void ungetch(int c) {
  if (bufp >= BUFSIZE) {
    printf("ungetch: too many characters\n");
  } else {
    buf[bufp++] = c;
  }
}

