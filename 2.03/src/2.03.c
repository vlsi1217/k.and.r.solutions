#include <stdio.h>
#include <stdlib.h>

/*
 * Write a function htoi(s), which converts a string of hexadecimal digits
 * (including an optional 0x or 0X) into its equivalent integer value. The
 * allowable digits are 0 through 9, a through f, and A through F.
 *
 */

int htoi(char s[]);

int main() {
  char* line = NULL;
  ssize_t read;
  size_t len = 0;

  while((read = getline(&line, &len, stdin)) != -1) {
    printf("%i", htoi("foo"));
  }

  exit(EXIT_SUCCESS);
}

int htoi(char s[]) {
  return 0;
}

