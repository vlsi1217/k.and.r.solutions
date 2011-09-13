#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#include "calculator.h"
#include "stack.h"
#include "getch.h"

/*
 *  Apply an operation to the stack
 *
 */

void applyop(char type, char operation[]) {
  double op2;

  switch(type) {
  case NUMBER:
    push(atof(operation));
    break;
  case '+':
    push(pop() + pop());
    break;
  case '*':
    push(pop() * pop());
    break;
  case '-':
    op2 = pop();
    push(pop() - op2);
    break;
  case '/':
    if((op2 = pop())) {
      push(pop() / op2);
    } else {
      printf("error: zero divisor: %.8g\n", op2);
    }
    break;
  case '\n':
    printf("%.8g\n", pop());
    break;
  default:
    printf("error: unknown operation %s\n", operation);
    break;
  }
}

/*
 * Get next character or numeric operand
 *
 */

int getop(char s[]) {
  int i, c;

  while((s[0] = c = getch()) == ' ' || c == '\t') {}

  s[1] = '\0';

  if(!isdigit(c) && c != '.') { // not a number
    return c;
  }

  i = 0;

  // collect remaining integer part

  if(isdigit(c)) {
    while(isdigit(s[++i] = c = getch())) {}
  }

  // collect fraction part

  if (c == '.') {
    while(isdigit(s[++i] = c = getch())) {}
  }

  s[i] = '\0';

  if(c != EOF) {
    ungetch(c);
  }

  return NUMBER;
}

