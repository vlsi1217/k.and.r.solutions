#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAXOP 100     // max size of operand or operator
#define NUMBER '0'    // signal that a number was found
#define MAXVAL 100
#define MAXLINE 1024

// calculator

int getop(char op[]);
void skip_whitespace(void);
int is_whitespace(void);
int is_operator(void);
int is_eol(void);

// stack

void push(double);
double pop(void);

// utils

int getline2(char line[], int maxchars);

// shared state

int lp = 0;          // points to getop position in input line
char line[MAXLINE];  // input line
int sp = 0;          // next free stack position
double val[MAXVAL];  // value stack

/*
 * An alternate organization uses getline to read an entire input line; this
 * makes getch and ungetch unnecessary. Revise the calculator to use this
 * approach.
 *
 */

int main() {
  char op[MAXOP + 1];
  int type;
  double op2;

  while(getline2(line, MAXLINE) >= 0) {
    lp = 0;

    while((type = getop(op)) != '\0') {
      switch(type) {
      case NUMBER:
        push(atof(op));
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
      default:
        printf("error: unknown command %s\n", op);
        break;
      }
    }

    printf("%.8g\n", pop());
  }

  exit(EXIT_SUCCESS);
}

/*
 * Get next character or numeric operand
 *
 */

int getop(char op[]) {
  int op_i;
  char ret;

  skip_whitespace();

  op_i = 0;

  if(is_eol()) {
    ret = '\0';

  } else if(is_operator()) {
    ret = line[lp];
    op[op_i++] = line[lp++];

  } else {
    while(!is_whitespace() && !is_eol()) {
      op[op_i++] = line[lp++];
    }

    ret = NUMBER;
  }

  op[op_i] = '\0';

  return ret;
}

/*
 *  Move lp forward to the next character.
 *
 */

void skip_whitespace() {
  while(is_whitespace()) {
    lp++;
  }
}

/*
 * Spaces and tabs.
 *
 */

int is_whitespace() {
  return line[lp] == ' ' || line[lp] == '\t';
}

/*
 * End of the line
 *
 */

int is_eol() {
  return line[lp] == '\0';
}

/*
 * Operations
 *
 */

int is_operator() {
  char c = line[lp];
  char n = line[lp + 1];

  return ((c == '+' || c == '-') && !isdigit(n)) || c == '*' || c == '/';
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
 * `getline` implementation from chapter 1.
 *
 */

int getline2(char line[], int maxchars) {
  int c, length, copied;
  copied = 0;

  for(length = 0; (c = getchar()) != EOF && c != '\0' && c != '\n'; length++) {
    if(copied < maxchars) {
      line[copied++] = c;
    }
  }

  line[copied] = '\0';

  if(c == EOF && length == 0) {
    return -1;
  } else {
    return length;
  }
}

