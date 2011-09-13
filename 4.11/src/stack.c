#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

#define MAXVAL 100

void push(double);
double pop(void);

int sp = 0;           // next free stack position
double val[MAXVAL];   // value stack

/*
 * Push f onto value stack
 *
 */

void push(double f) {
  if(sp < MAXVAL) {
    val[sp++] = f;
  } else {
    printf("error: stack full, can't push %g\n", f);
  }
}

/*
 * Pop and return top value from stack
 *
 */

double pop(void) {
  if(sp > 0) {
    return val[--sp];
  } else {
    printf("error: stack empty\n");
    return 0.0;
  }
}

