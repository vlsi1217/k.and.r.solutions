#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <time.h>

int binsearch(int x, int sorted[], int n);
int getline2(char line[], int maxchars);

#define MAX_LINE_LENGTH 256
#define MAX_VALUES 1000000

int main(int argc, char *argv[]) {
  int sorted[MAX_VALUES];
  int i, length, opt, key, result, timed = 0, iterations = 1;
  char line[MAX_LINE_LENGTH];
  clock_t time;

  // parse command-line

  while((opt = getopt(argc, argv, "tk:i:")) != -1) {
    switch (opt) {
    case 't':
      timed = 1;
      break;
    case 'k':
      key = atoi(optarg);
      break;
    case 'i':
      iterations = atoi(optarg);
      break;
    default: /* '?' */
      fprintf(stderr, "Usage: %s [-t ] [-k key]\n", argv[0]);
      exit(EXIT_FAILURE);
    }
  }

  // build the list

  for(length = 0; (getline2(line, MAX_LINE_LENGTH)) >= 0 && length < MAX_VALUES; length++) {
    sorted[length] = atoi(line);
  }

  // clocked invocation

  time = clock();

  for(i = 0; i < iterations; i++) {
    result = binsearch(key, sorted, length);
  }

  time = clock() - time;

  timed ? printf("%f\n", time * 1.0) : printf(":%i\n", result);

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

  while(low <= high && sorted[mid] != key) {
    mid = (low + high) / 2;

    if(key < sorted[mid]) {
      high = mid - 1;

    } else {
      low = mid + 1;

    }

    if(sorted[mid] == key) {
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

