#include <stdio.h>

/*
 * Write a loop equivalent to the for getline input function shown below
 * without using \&\& or \|\|.
 *
 * for (i = 0; i < lim - 1 \&\& (c = getchar()) != '\n' \&\& c != EOF; ++i) {
 *   putchar(c);
 * }
 *
 */

#define LIMIT 11

int main() {
  int lim = LIMIT;
  int i, c;

  for (i = 0; i < lim - 1; ++i) {
    c = getchar();

    if(c == '\n') { return 0; }
    if(c == EOF) { return 0; }

    putchar(c);
  }

  return 0;
}

