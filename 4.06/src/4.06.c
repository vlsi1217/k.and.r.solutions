#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

#define MAXOP 100       // max size of operand or operator
#define NUMBER '0'      // signal that a number was found
#define STORE 's'
#define MAXVAL 100
#define BUFSIZE 100
#define VARIABLES 30

int getop(char []);
void push(double);
double pop(void);

int sp = 0;             // next free stack position
double val[MAXVAL];     // value stack

int getch(void);
void ungetch(int);
int is_variable(char c);

char buf[BUFSIZE];      // buffer for ungetch
int bufp = 0;           // next free position in buf
double vars[VARIABLES] = { 0 };

/*
 * Add commands for handling variables. (It's easy to provide twenty-six
 * variables with single-letter names.) Add a variable for the most recently
 * printed value.
 *
 * Solution
 * --------
 *
 * Variables are stored into one of a..z using operation `s`. To store into p:
 *
 *   3.1415 sp
 *
 * The most recently printed value is stored in the automatic variable ~.
 *
 */

int main() {
  int type;
  double op2;
  char s[MAXOP];

  while((type = getop(s)) != EOF) {
    switch(type) {
    case NUMBER:
      push(atof(s));
      break;
    case STORE:
      push(vars[s[0] - 'a'] = pop());
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
        printf("error: zero divisor\n");
      }
      break;
    case '%':
      op2 = pop();
      push(fmod(pop(), op2));
      break;
    case '^':
      op2 = pop();
      push(pow(pop(), op2));
      break;
    case 'S':
      push(sin(pop()));
      break;
    case 'E':
      push(exp(pop()));
      break;
    case '\n':
      printf("%.8g\n", (vars['~' - 'a'] = pop()));
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

/*
 * Get next character or numeric operand
 *
 */

int getop(char s[]) {
  int i, c, next;

  while((s[0] = c = getch()) == ' ' || c == '\t') {}

  s[1] = '\0';

  // store top of the stack into a variable

  if(c == 's') {
    if((next = getch()) && is_variable(next)) {
      s[0] = next;
      s[1] = '\0';

      return STORE;
    }

    ungetch(next);
  }

  // convert to value

  if(is_variable(c)) {
    if((next = getch()) == ' ' || next == '\t') {
      sprintf(s, "%f", vars[c - 'a']);

      return NUMBER;
    }

    ungetch(next);
  }

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

/*
 * Valid variable identifiers are a-z and the automatic ~.
 *
 */

int is_variable(char c) {
  return (c >= 'a' && c <= 'z') || c == '~';
}

