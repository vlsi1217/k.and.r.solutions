#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 100

int getch(void);
void ungets(const char input[]);
void ungetch(int);

char buf[BUFSIZE];  // buffer for ungetch
int bufp = 0;       // next free position in buf

/*
 * Write a routine ungets(s) that will push back an entire string onto the
 * input. Should ungets know about buf and bufp, or should it just use
 * ungetch?
 *
 * Solution
 * --------
 *
 * `ungetch` is the only primitive needed to build `ungets`. It is made
 * testable with an echo implementation.
 *
 */

int main() {
  char line[BUFSIZE + 1];
  int c, line_i;

  line_i = 0;

  while((c = getch()) != EOF) {
    line[line_i++] = c;

    if(c == '\n' || line_i > BUFSIZE) {
      line[line_i] = '\0';
      ungets(line);
      line_i = 0;

      while(putchar(getch())) {}
    }
  }
}

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

/*
 * Push string back onto input
 *
 */

void ungets(const char input[]) {
  int input_i = strlen(input);

  while(input_i >= 0) {
    ungetch(input[input_i--]);
  }
}

