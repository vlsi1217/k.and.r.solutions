#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAXOP 100     // max size of operand or operator
#define POSITIVE '0'  // signal that a positive number was found
#define NEGATIVE '1'  // signal that a negative number was found
#define MAXVAL 100
#define BUFSIZE 100

int getop(char []);
void push(double);
double pop(void);

int sp = 0;           // next free stack position
double val[MAXVAL];   // value stack

int getch(void);
void ungetch(int);

char buf[BUFSIZE];    // buffer for ungetch
int bufp = 0;         // next free position in buf

/*
 * Add the modulus (%) operator and provisions for negative numbers.
 *
 */

int main() {
  int type;
  double op2;
  char s[MAXOP];

  while((type = getop(s)) != EOF) {
    switch(type) {
    case POSITIVE:
      push(atof(s));
      break;
    case NEGATIVE:
      push(-1.0 * atof(s));
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
      op2 = pop();
      if(op2 != 0.0) {
        push(pop() / op2);
      } else {
        printf("error: zero divisor\n");
      }
      break;
    case '%':
      op2 = pop();
      push(fmod(pop(), op2));
      break;
    case '\n':
      printf("%.8g\n", pop());
      break;
    default:
      printf("error: unknown command %s\n", s);
      break;
    }
  }

  return 0;
}

/*
 * Push f onto value stack
 *
 */

void push(double f) {
  if (sp < MAXVAL) {
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
  if (sp > 0) {
    return val[--sp];
  } else {
    printf("error: stack empty\n");
    return 0.0;
  }
}

/*
 * Get next character or numeric operand
 *
 */

int getop(char s[]) {
  int i, c, next;
  int sign = 1;

  while((s[0] = c = getch()) == ' ' || c == '\t') {}

  s[1] = '\0';

  // negative number starting

  if(c == '-') {
    if(isdigit(next = getch())) {
      s[0] = c = next;
      sign = -1;
    } else {
      ungetch(next);
    }
  }

  if(!isdigit(c) && c != '.') { // not a number
    return c;
  }

  i = 0;

  // collect remaining integer part

  if(isdigit(c)) {
    while(isdigit(s[++i] = c = getch())) {
    }
  }

  // collect fraction part

  if (c == '.') {
    while(isdigit(s[++i] = c = getch())) {}
  }

  s[i] = '\0';

  if(c != EOF) {
    ungetch(c);
  }

  return sign > 0 ? POSITIVE : NEGATIVE;
}

/*
 * Get a (possibly pushed-back) character
 *
 */

int getch(void) {
  return (bufp > 0) ? buf[--bufp] : getchar();
}

/*
 * Push character back on input
 *
 */

void ungetch(int c) {
  if (bufp >= BUFSIZE) {
    printf("ungetch: too many characters\n");
  } else {
    buf[bufp++] = c;
  }
}

