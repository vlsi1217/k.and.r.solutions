#include <stdio.h>

int getline(char line[], int maxlen);

#define MAX_LINE_LENGTH 80

main() {
  int length = 0;
  char line[MAX_LINE_LENGTH];

  while((length = trimmed_line(line, MAX_LINE_LENGTH)) >= 0) {
    if(length > 0) {
      printf("%s", line);
      printf("\n");
    }
  }

  return 0;
}

int trimmed_line(char line[], int maxlen) {
  int c, length, copied, end;
  copied = 0;

  for(length = 0; (c = getchar()) != EOF && c != '\0' && c != '\n'; length++) {
    if(copied < maxlen - 1) {
      line[copied++] = c;
    }
  }

  // terminate the string. move backwards until non-whitespace is encountered.
  line[copied] = '\0';

  for(end = copied - 1; end >= 0; end--) {
    if(line[end] == ' ' || line[end] == '	') {
      line[end] = '\0';
      length--;
    } else {
      break;
    }
  }

  if(length == 0 && c == EOF) {
    return -1;
  } else {
    return length;
  }
}
