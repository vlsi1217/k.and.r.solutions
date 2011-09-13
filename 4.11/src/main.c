#include <stdio.h>
#include <stdlib.h>
#include "calculator.h"

#define MAXOP 100     // max size of operand or operator

/*
 * A reverse polish notation calculator. Unmodified version.
 *
 */

int main() {
  int type;
  char s[MAXOP];

  while((type = getop(s)) != EOF) {
    applyop(type, s);
  }

  exit(EXIT_SUCCESS);
}

