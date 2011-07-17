#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

int getline2(char line[], int maxchars);
int strpbrk2(char input[], char list[]);
void to_bitmask(char list[], unsigned long int bitmask[]);

#define MAX_LINE_LENGTH 1024
#define BUCKET_WIDTH 64 // will fail on 32 bit long platforms
#define BITMASK_BUCKETS (UCHAR_MAX + 1) / BUCKET_WIDTH

/*
 *  Write the function any(s1,s2), which returns the first location in
 *  a string s1 where any character from the string s2 occurs, or -1 if s1
 *  contains no characters from s2. (The standard library function strpbrk
 *  does the same job but returns a pointer to the location.)
 *
 */

int main(int argc, char *argv[]) {
  int length;
  char line[MAX_LINE_LENGTH];

  while((length = getline2(line, MAX_LINE_LENGTH)) >= 0) {
    printf("%i\n", strpbrk2(line, argv[1]));
  }

  exit(EXIT_SUCCESS);
}

/*
 *  Returns the first location in a string `input` where any character from
 *  `list` occurs, or -1 is `input` contains no characters from `list`.
 *
 *  Uses a bitmask to find the first banned character in one linear pass.
 *  Could be constant space by passing a stream.
 *
 */

int strpbrk2(char input[], char list[]) {
  unsigned long int bitmask[BITMASK_BUCKETS] = { 0 };
  int i, bucket, offset;

  to_bitmask(list, bitmask);

  for(i = 0; input[i] != '\0'; i++) {
    bucket = input[i] / BUCKET_WIDTH;
    offset = input[i] - (bucket * BUCKET_WIDTH);

    if(bitmask[bucket] & 1 << offset) {
      return i;
    }
  }

  return -1;
}

/*
 *  Bitmask maps `UCHAR_MAX` number of glyphs onto a split bitmask, because
 *  256 bits are needed to represent all chars. There are `BITMASK_BUCKETS`
 *  buckets, each 64 bits wide (unsigned long int).
 *
 */

void to_bitmask(char list[], unsigned long int bitmask[]) {
  int i, bucket, offset;

  for(i = 0; list[i] != '\0'; i++) {
    bucket = list[i] / BUCKET_WIDTH;
    offset = list[i] - bucket * BUCKET_WIDTH;

    bitmask[bucket] |= 1 << offset;
  }
}

/*
 *  Chapter 1 `getline` implementation without pointers.
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

