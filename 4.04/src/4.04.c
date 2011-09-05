#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmd(const char line[], char argument[]);
int getexpr(char line[], int maxchars);
void guard(void);

double pop(void);
void push(double);

void clear(void);
void cp(char target[]);
void help(void);
void peek(int n);
void use(char n[]);
void swap(void);

#define MAX_LINE_LENGTH 1024
#define COMMANDS 8
#define MAXVAL 100
#define BUFSIZE 100
#define MAXNAME 100
#define STACKS 26

// xxx redundant command and commands and COMMANDS

enum commands { CLEAR, CP, HELP, PEEK, POP, PUSH, SWAP, USE };
const char* command[COMMANDS] = {
  "clear",
  "cp",
  "help",
  "peek",
  "pop",
  "push",
  "swap",
  "use"
};

// global state

int stack = -1;
int pointers[STACKS] = { 0 };
double vals[STACKS][MAXVAL];

/*
 * Add the commands to print the top elements of the stack without popping, to
 * duplicate it, and to swap the top two elements. Add a command to clear the
 * stack.
 *
 */

int main() {
  char arg[MAX_LINE_LENGTH + 1];
  char line[MAX_LINE_LENGTH + 1];

  while(getexpr(line, MAX_LINE_LENGTH)) {
    switch(cmd(line, arg)) {
    case CLEAR:
      guard();
      clear();
      break;
    case CP:
      guard();
      cp(arg);
      break;
    case HELP:
      help();
      break;
    case PEEK:
      guard();
      peek(atoi(arg));
      break;
    case POP:
      guard();
      pop();
      break;
    case PUSH:
      guard();
      push(atoi(arg));
      break;
    case SWAP:
      guard();
      swap();
      break;
    case USE:
      use(arg);
      break;
    default:
      printf("error: `%s` is not a valid cmd. try `help`.\n", line);
      exit(EXIT_FAILURE);
    }
  }

  exit(EXIT_SUCCESS);
}

/*
 * Returns the command code and arguments, or -1 if no command was recognized.
 *
 */

int cmd(const char line[], char arg[]) {
  int line_i, line_j, cmd_i, cmd_j, arg_i;

  line_i = 0;

  while(line[line_i] != '\0') {
    for(cmd_i = 0; cmd_i < COMMANDS; cmd_i++) {
      cmd_j = 0;
      line_j = line_i;

      while(line[line_j] == command[cmd_i][cmd_j] && line[line_j] != '\0') {
        cmd_j++;
        line_j++;
      }

      // found cmd

      if(line_j > 0 && (line[line_j] == ' ' || line[line_j] == '\0')) {
        arg_i = 0;

        // skip whitespace

        while(line[line_j] == ' ' || line[line_j] == '\t') {
          line_j++;
        }

        // copy arg

        while(line[line_j] != '\0') {
          arg[arg_i++] = line[line_j++];
        }

        arg[arg_i] = '\0';
        return cmd_i;
      }
    }

    line_i++;
  }

  arg[0] = '\0';
  return -1;
}

/*
 * Get stacking expressions
 *
 */

int getexpr(char line[], int max) {
  int c, line_i, started;

  line_i = 0;
  started = 0;

  while((c = getchar()) != EOF && c != '\n' && c != ';' && line_i < max) {

    // skip whitespace

    if(!started && (c != ' ' && c != '\t')) {
      started = 1;
    }

    if(started) {
      line[line_i++] = c;
    }
  }

  line[line_i] = '\0';

  return line_i;
}

/*
 * Abort unless a stack has been selected.
 *
 */

void guard() {
  if(stack < 0 || stack > STACKS) {
    printf("error: use <n> to begin session.\n");
    exit(EXIT_FAILURE);
  }
}

/*
 * Push f onto value stack
 *
 */

void push(double f) {
  if(pointers[stack] < MAXVAL) {
    vals[stack][pointers[stack]++] = f;
  } else {
    printf("error: stack full, can't push %g\n", f);
  }
}

/*
 * Pop and return top value from stack
 *
 */

double pop(void) {
  if(pointers[stack] > 0) {
    return vals[stack][--pointers[stack]];
  } else {
    printf("error: stack empty\n");
    return 0.0;
  }
}

/*
 * Clears the currently selected stack
 *
 */

void clear() {
  pointers[stack] = 0;
}

/*
 * Destructively copies the currently selected stack to the `target` stack.
 *
 */

void cp(char target[]) {
  int target_stack = target[0] - 'a';
  int i;

  if(strlen(target) != 1 || target_stack < 0 || target_stack > STACKS) {
    printf("error: `%s` is out of bounds. use one of a..z.\n", target);
    exit(EXIT_FAILURE);
  }

  for(i = 0; i < pointers[stack]; i++) {
    vals[target_stack][i] = vals[stack][i];
  }

  pointers[target_stack] = pointers[stack];
}

/*
 * Language help
 *
 */

void help() {
  int command_i;

  printf("the following commands are supported:\n");

  for(command_i = 0; command_i < COMMANDS; command_i++) {
    printf("  %s\n", command[command_i]);
  }
}

/*
 * Peek at the top n elements on the stack. Given 0, show all.
 *
 */

void peek(int n) {
  int i;

  if(n > pointers[stack] || n < 1) {
    n = pointers[stack];
  }

  for(i = 0; i < n; i++) {
    printf("%0.f", vals[stack][pointers[stack] - i - 1]);

    if(i != n - 1) {
      printf(", ");
    }
  }

  printf("\n");
}

/*
 * Use one of 26 stacks named a..z.
 *
 */

void use(char c[]) {
  if(strlen(c) != 1 || (stack = c[0] - 'a') < 0 || stack > STACKS) {
    printf("error: `%s` is out of bounds. use one of a..z.\n", c);
    exit(EXIT_FAILURE);
  }
}

/*
 * Swap the top two elements in the currently selected stack.
 *
 */

void swap() {
  int sp = pointers[stack] - 1;
  int tmp;

  if(sp) {
    tmp = vals[stack][sp - 1];
    vals[stack][sp - 1] = vals[stack][sp - 0];
    vals[stack][sp - 0] = tmp;
  }
}

