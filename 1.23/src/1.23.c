#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CODE 0
#define STRING 1
#define CHAR 2
#define COMMENT_OPENED_PRELUDE 3
#define COMMENT_CLOSED_PRELUDE 4
#define COMMENT 5

/*
 *  Strips comments from c code. Comments inside of string and character
 *  literals are not stripped.
 *
 */
int main() {
  int state = CODE;
  int character, last;

  while((last = character) && (character = getchar())) {
    if(character == EOF) {
      return 0;
    }

    // code state

    if(state == CODE) {
      if(character == '/') {
        state = COMMENT_OPENED_PRELUDE;

      } else if(character == '\'') {
        printf("%c", character);
        state = CHAR;

      } else if(character == '"') {
        printf("%c", character);
        state = STRING;

      } else {
        printf("%c", character);

      }

    // string state

    } else if(state == STRING ) {
      if(character == '"') {
        state = CODE;
      }

      printf("%c", character);

    // char state

    } else if(state == CHAR) {
      if(character == '\'') {
        state = CODE;
      }

      printf("%c", character);

    // comment opened prelude state

    } else if(state == COMMENT_OPENED_PRELUDE) {
      if(character == '*') {
        state = COMMENT;

      } else {
        printf("%c", last);
        printf("%c", character);
        state = CODE;
      }

    // comment closed prelude state

    } else if(state == COMMENT_CLOSED_PRELUDE){
      if(character == '/') {
        state = CODE;

      } else {
        state = COMMENT;
      }

    // comment state

    } else if(state == COMMENT){
      if(character == '*') {
        state = COMMENT_CLOSED_PRELUDE;
      }
    }
  }

  return 1; // should never arrive here.
}
