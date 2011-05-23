#include <stdio.h>

// signatures

int machine(int state, int c, int last);

// states

#define CODE 0
#define STRING 1
#define CHAR 2
#define COMMENT_OPENED_PRELUDE 3
#define COMMENT_CLOSED_PRELUDE 4
#define COMMENT 5
#define CPP_COMMENT 6

// stack

#define MAX_STACK 128
#define GLYPHS 3

/*
 *  Checks a C file for basic syntax errors, including unbalanced tokens.
 *
 *    Example: }
 *
 */
int main() {
  char* tokens[GLYPHS] = { "()", "{}", "[]" };
  char stack[MAX_STACK] = { '\0' };
  int current, last, line, chr, spointer, state, glyph;

  chr = 0;
  line = 1;
  spointer = 0;
  state = CODE;

  while((last = current) && (current = getchar()) && current != EOF) {
    if(current == '\n') {
      line++;
      chr = 0;

    } else {
      chr++;

    }

    state = machine(state, current, last);

    if(state == CODE) {
      for(glyph = 0; glyph < GLYPHS; glyph++) {

        /* open. ie [ */
        if(current == tokens[glyph][0]) {
          stack[spointer++] = current;
        }

        // close, ie )
        if(current == tokens[glyph][1]) {
          if(stack[spointer - 1] != tokens[glyph][0]) {
            printf("contains unbalanced %c at %d:%d.\n", current, line, chr);
            printf("stack: %s\n", stack);
            return current;

          } else {
            stack[spointer] = '\0';
            spointer--;

          }
        }
      }
    }
  }

  char token;

  if(spointer != 0 || state == STRING || state == CHAR) {
    if(state == STRING) {
      token = '"' ;

    } else if(state == CHAR) {
      token = '\'';

    } else {
      token = stack[spointer - 1];

    }

    printf("unclosed %c at end of file.\n", token);
    return current;
  }

  return 0;
}

int machine(int state, int current, int last) {

  // code state

  if(state == CODE) {
    if(current == '/') {
      state = COMMENT_OPENED_PRELUDE;

    } else if(current == '\'') {
      state = CHAR;

    } else if(current == '"') {
      state = STRING;

    }

  // string state

  } else if(state == STRING ) {
    if(current == '"' && last != '\\') {
      state = CODE;
    }

  // char state

  } else if(state == CHAR) {
    if(current == '\'' && last != '\\') {
      state = CODE;
    }

  // comment opened prelude state

  } else if(state == COMMENT_OPENED_PRELUDE) {
    if(current == '*') {
      state = COMMENT;

    } else if(current == '/') {
      state = CPP_COMMENT;

    } else {
      state = CODE;

    }

  // comment closed prelude state

  } else if(state == COMMENT_CLOSED_PRELUDE) {
    if(current == '/') {
      state = CODE;

    } else {
      state = COMMENT;
    }

  // c++ comment state

  } else if(state == CPP_COMMENT) {
    if(current == '\n') {
      state = CODE;

    }

  // comment state

  } else if(state == COMMENT) {
    if(current == '*') {
      state = COMMENT_CLOSED_PRELUDE;
    }
  }

  return state;
}
