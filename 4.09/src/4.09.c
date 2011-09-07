#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 100

int getch(void);
void ungetch(int);

char buf[BUFSIZE];  // buffer for ungetch
int bufp = 0;       // next free position in buf

/*
 * Our getch and ungetch do not handle a pushed-back EOF correctly. Decide
 * what their properties ought to be if an EOF is pushed back, then implement
 * your design.
 *
 * Solution
 * --------
 *
 * EOF is not in the char range and cannot be stored in the char array buffer,
 * as explained in chapter 1:
 *
 *   "The solution is that getchar returns a distinctive value when there is no
 *   more input, a value that cannot be confused with any real character. This
 *   value is called EOF, for ``end of file''. We must declare c to be a type
 *   big enough to hold any value that getchar returns. We can't use char
 *   since c must be big enough to hold EOF in addition to any possible char.
 *   Therefore we use int"
 *
 * However, using the provided Makefile on Linux and OSX, this does not appear
 * to be true. Here EOF is defined as:
 *
 *   #define EOF -1
 *
 * which is 'FF' in a two's complement representation. 'FF' (255) is an
 * unprintable unsigned char value, so this program works without changing the
 * array to int.
 *
 * I'm not certain if this is the intended 'design'.
 *
 */

int main() {
  int c;

  while((c = getch()) != EOF) {
    putchar(c);
  }

  ungetch(c);

  if(getchar() != EOF) {
    exit(EXIT_FAILURE);
  }

  exit(EXIT_SUCCESS);
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
  if(bufp >= BUFSIZE) {
    printf("ungetch: too many characters\n");
  } else {
    buf[bufp++] = c;
  }
}

