#include <stdio.h>

/*
 * Verify that the expression getchar() != EOF is 0 or 1.
 *
 */

int main() {
  int c;

  while((c = getchar()) != EOF) {
    printf("%i", c != EOF);
  }

  printf("%i", c != EOF);
  return 0;
}

