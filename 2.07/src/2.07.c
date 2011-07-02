#include <stdio.h>
#include <stdlib.h>

unsigned int invert(unsigned int x, int p, int n);
unsigned int mask(int index, int n);

/*
 * Write a function invert(x,p,n) that returns x with the n bits that begin at
 * position p inverted (i.e., 1 changed into 0 and vice versa), leaving the
 * others unchanged.
 *
 */

int main(int argc, char *argv[]) {
  printf("%i", invert(atoi(argv[1]), atoi(argv[2]), atoi(argv[3])));

  exit(EXIT_SUCCESS);
}


/*
 *  XORing a value y with 1 will will produce the complement of y.
 *
 */

unsigned int invert(unsigned int x, int p, int n) {
  return x ^ mask(p, n);
}

/*
 *  Masks with n 1s starting at position p.
 *
 */

unsigned int mask(int p, int n) {
  return ~(~0 << n) << p - n;
}

