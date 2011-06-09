#include <stdio.h>

/*
 * Write a program to print the value of EOF.
 *
 */

int main() {
  putchar('0');
  putchar('9');
  putchar('a');
  putchar('z');
  putchar('A');
  putchar('Z');
  putchar('\t');
  putchar('\b');
  putchar('\n');
  putchar('\0');
  putchar(EOF);

  return 0;
}
