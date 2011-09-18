#include <stdio.h>
#include <stdlib.h>

#define swap(t,x,y) \
  if(1) {           \
    t tmp = (x);    \
    tmp = (x);      \
    (x) = (y);      \
    (y) = tmp;      \
  }

int main() {
  char a, b;

  a = getchar();
  b = getchar();

  swap(char, a, b);

  putchar(a);
  putchar(b);

  exit(EXIT_SUCCESS);
}

