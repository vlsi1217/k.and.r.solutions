#include <stdio.h>

void display(char gram[]);
void display_bar(int height);
void display_label(int letter);
void histogram();
int normalize(char letter);

main() {
  histogram();
}

/*
 *  Builds a histogram of characters found in STDIN.
 *
 */

void histogram() {
  char gram[26];
  int c;

  while((c = getchar()) != EOF) {
    int normalized = normalize(c);
    if(normalized >= 0) {
      if(gram[normalized]) {
        gram[normalized]++;
      } else {
        gram[normalized] = 1;
      }
    }
  }

  display(gram);
}

/*
 * Prints the histogram.
 *
 */

void display(char gram[]) {
  int i;

  for(i = 0; i <= 25; i++) {
    display_label(i + 97);
    display_bar(gram[i]);
    printf("\n");
  }
}

/*
 * Prints a label
 *
 */

void display_label(label) {
  printf("%c ", label);
}

/*
 * Prints a bar
 *
 */

void display_bar(height) {
  int i;

  for(i = 0; i < height; i++) {
    printf("█");
  }
}

/*
 * Converts upper or lowercase letters to int 0 - 25.
 * All other characters are converted to -1.
 *
 */

int normalize(char letter) {
  if(letter >= 65 && letter <= 90) {
    return letter - 65;
  } else if(letter >= 97 && letter <= 122) {
    return letter - 97;
  } else {
    return -1;
  }
}