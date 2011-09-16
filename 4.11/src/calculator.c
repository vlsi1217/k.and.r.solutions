#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "calculator.h"
#include "stack.h"

#define BOF -129

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
  static int c = BOF;
  int i;

  // remove whitespace

  while(c == BOF || c == ' ' || c == '\t') {
   s[0] = c = getchar();
  }

  s[1] = '\0';

  if(!isdigit(c) && c != '.') { // not a number
    int op = c;
    c = getchar();

    return op;
  }

  i = 0;

  // collect remaining integer part

  while(isdigit(c)) {
    s[++i] = c = getchar();
  }

  // collect fraction part

  if(c == '.') {
    s[++i] = c = getchar();
  }

  while(isdigit(c)) {
    s[++i] = c = getchar();
  }

  s[i] = '\0';

  return NUMBER;
}

