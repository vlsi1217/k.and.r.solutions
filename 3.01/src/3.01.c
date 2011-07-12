#include <stdio.h>
#include <stdlib.h>

int binsearch(int x, int sorted[], int n);
int getline2(char line[], int maxchars);

#define MAX_LINE_LENGTH 256
#define MAX_VALUES 1000000

int main(int argc, char *argv[]) {
  char line[MAX_LINE_LENGTH];
  int sorted[MAX_VALUES];
  int key = atoi(argv[1]);
  int i;

  for(i = 0; (getline2(line, MAX_LINE_LENGTH)) >= 0 && i < MAX_VALUES; i++) {
    sorted[i] = atoi(line);
  }

  printf(":%i\n", binsearch(key, sorted, i));
  exit(EXIT_SUCCESS);
}

/*
 * Binary search implementation.
 *
 */

int binsearch(int key, int sorted[], int length) {
  int low = 0;
  int high = length - 1;
  int mid;

  while(low <= high) {
    mid = (low + high) / 2;

    if(key < sorted[mid]) {
      high = mid - 1;

    } else if(key > sorted[mid]) {
      low = mid + 1;

    } else {
      return mid;

    }
  }

  return -1;
}

/*
 * getline implementation from chapter 1.
 *
 */

int getline2(char line[], int maxchars) {
  int c, length, copied;
  copied = 0;

  for(length = 0; (c = getchar()) != EOF && c != '\0' && c != '\n'; length++) {
    if(copied < maxchars - 1) {
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

