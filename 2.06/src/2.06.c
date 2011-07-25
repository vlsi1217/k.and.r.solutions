#include <stdio.h>
#include <stdlib.h>

unsigned int delete(unsigned int x, int index, int n);
unsigned int mask(int index, int n);
unsigned int mask_bottom(int n);
unsigned int rightmost(unsigned int y, int n);
unsigned int setbits(unsigned int x, int p, int n, unsigned int y);

/*
 * Write a function setbits(x,p,n,y) that returns x with the n bits that begin
 * at position p set to the rightmost n bits of y, leaving the other bits
 * unchanged.
 *
 */

int main(int argc, char *argv[]) {
  unsigned int x = atoi(argv[1]);
  int p = atoi(argv[2]);
  int n = atoi(argv[3]);
  unsigned int y = atoi(argv[4]);

  printf("%u", setbits(x, p, n, y));

  exit(EXIT_SUCCESS);
}

/*
 * Returns x with the n bits that begin at position p set to the rightmost
 * n bits of y.
 *
 */

unsigned int setbits(unsigned int x, int p, int n, unsigned int y) {
  int index = p + 1;

  return (delete(x, index, n) + rightmost(y, n)) << (index - n);
}

/*
 * Return the rightmost n bits of y
 *
 */

unsigned int rightmost(unsigned int y, int n) {
  return mask_bottom(n) & y;
}

/*
 * Delete n bits from x, starting at index.
 *
 */

unsigned int delete(unsigned int x, int index, int n) {
  return mask(index, n) & x;
}

/*
 * Masks n bitsp, starting at index.
 *
 */

unsigned int mask(int index, int n) {
  return (~0 << index) + mask_bottom(index - n);
}

/*
 * Masks n bottom bits
 *
 */

unsigned int mask_bottom(int n) {
  return ~(~0 << n);
}

