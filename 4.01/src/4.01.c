#include <stdio.h>
#include <getopt.h>
#include <stdlib.h>
#include <string.h>

int getline2(char line[], int maxchars);
int strindex(char s[], char t[]);
void usage();

#define MAX_LENGTH 1024

/*
 *  Write the function strindex(s,t) which returns the position of the
 *  rightmost occurrence of t in s, or -1 if there is none.
 *
 */

int main(int argc, char* argv[]) {
  char line[MAX_LENGTH + 1] = { 0 };
  char term[MAX_LENGTH + 1] = { 0 };
  int length = 0;
  int index = -1;
  int opt = -1;

  // parse command-line

  while((opt = getopt(argc, argv, "s:")) != -1) {
    switch(opt) {
    case 's':
      strcpy(term, optarg);
      break;
    default:
      usage();
      exit(EXIT_FAILURE);
    }
  }

  if(strlen(term) == 0) {
    usage();
    exit(EXIT_FAILURE);
  }

  if((length = getline2(line, MAX_LENGTH)) > 0) {
    index = strindex(line, term);
    printf("%d\n", index);
    exit(index);
  }

  exit(EXIT_FAILURE);
}

int strindex(char input[], char term[]) {
  int input_i, input_j, term_i, offset;

  offset = -1;

  for(input_i = 0; input[input_i] != '\0'; input_i++) {
    input_j = input_i;
    term_i = 0;

    while(term[term_i] != '\0' && input[input_j] == term[term_i]) {
      input_j++;
      term_i++;
    }

    if(term[term_i] == '\0' && term_i > 0) {
      offset = input_i;
    }
  }

  return offset;
}

void usage() {
  fprintf(stderr, "Usage: 4.01 [-s search_term]\n");
}

/*
 * getline implementation from chapter 1.
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

