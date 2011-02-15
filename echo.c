#include <stdio.h>

/*
 * Read a line
 *
 */

char[] read_line() {
  int c;
  char[] buffer;

  while(c = getchar() != EOF) {
    buffer += c;
    printf("added to buffer");
  }

  return buffer;
}

/*
 * Echo input
 *
 */

main() {
  for(;;) {
    printf("tippled: %c\n", read_line());
  }
}
