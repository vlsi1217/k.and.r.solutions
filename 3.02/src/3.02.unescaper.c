#include <stdio.h>
#include <stdlib.h>

int unescape(char input[], char escaped[]);

#define MAX_CHARS 1000

/*
 * Write a function for the other direction as well, converting escape
 * sequences into the real characters.
 *
 */

int main() {
  char line[MAX_CHARS + 1] = { 0 };
  char unescaped[MAX_CHARS + 1] = { 0 };
  int i, c;

  for(i = 0; (c = getchar()) != EOF && i < MAX_CHARS; i++) {
    line[i] = c;
  }

  unescape(line, unescaped);
  printf("%s", unescaped);

  exit(EXIT_SUCCESS);
}

int unescape(char input[], char unescaped[]) {
  int i, j;

  for(i = 0, j = 0; input[i] != '\0'; i++, j++) {
    if(input[i] == '\\') {
      switch(input[i + 1]) {
       case 'n':
         unescaped[j] = '\n';
         i++;
         break;
       case 't':
         unescaped[j] = '\t';
         i++;
         break;
       default:
         unescaped[j] = input[i];
         break;
      }

     } else {
        unescaped[j] = input[i];
     }
  }

  unescaped[j] = '\0';

  return 0;
}

