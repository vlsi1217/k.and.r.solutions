#include <stdio.h>
#include <stdlib.h>

int escape(char input[], char escaped[]);

#define MAX_CHARS 100000

/*
 * Write a function escape(s,t) that converts characters like newline and tab
 * into visible escape sequences like \n and \t as it copies the string t to
 * s. Use a switch.
 *
 */

int main() {
  char line[MAX_CHARS + 1] = { 0 };
  char escaped[MAX_CHARS + 1] = { 0 };
  int i, c;

  for(i = 0; (c = getchar()) != EOF && i < MAX_CHARS; i++) {
    line[i] = c;
  }

  escape(line, escaped);
  printf("%s", escaped);

  exit(EXIT_SUCCESS);
}

int escape(char input[], char escaped[]) {
  int i, j;

  for(i = 0, j = 0; input[i] != '\0' && j < MAX_CHARS; i++, j++) {
     switch(input[i]) {
      case '\t':
        escaped[j] = '\\';
        escaped[++j] = 't';
        break;
      case '\n':
        escaped[j] = '\\';
        escaped[++j] = 'n';
        break;
      default:
        escaped[j] = input[i];
        break;
    }
  }

  escaped[j] = '\0';

  return 0;
}

