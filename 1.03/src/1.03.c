#include <stdio.h>

/*
 * Modify the temperature conversion program to print a heading above the
 * table.
 *
 */

int main() {
  float fahr, celsius;
  float lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;

  fahr = lower;

  printf("fahrenheit  celcius\n");

  while (fahr <= upper) {
    celsius = (5.0 / 9.0) * (fahr - 32.0);
    printf("%10.0f %8.1f\n", fahr, celsius);
    fahr = fahr + step;
  }
}

