#include <stdio.h>

float to_celsius(float fahr);

/*
 * Rewrite the temperature conversion program of Section 1.2 to use a function
 * for conversion.
 *
 */

int main() {
  float fahr;
  float lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;

  fahr = lower;

  printf("fahrenheit  celcius\n");

  while (fahr <= upper) {
    printf("%10.0f %8.1f\n", fahr, to_celsius(fahr));
    fahr = fahr + step;
  }
}

float to_celsius(float fahr) {
  return (5.0 / 9.0) * (fahr - 32.0);
}
