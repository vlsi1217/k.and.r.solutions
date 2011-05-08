#include <stdio.h>

int main() {
  int c, i, j;
  int counters[255] = { 0 }; // one byte

  while((c = getchar()) != EOF) {
    counters[c] += 1;
  }

  for(i = 33; i < 127; i++) {
    printf("%c: ", i);

    for(j = 0; j < counters[i]  ; j++) {
      printf("█");
    }

    printf("\n");
  }
}
