#include <stdio.h>

int main() {
  int c;

  while((c = getchar()) != EOF) {
    printf("%i", c != EOF);
  }

  printf("%i", c != EOF);
  return 0;
}
