#include <stdio.h>

#define UPPER 100
#define STEP 10

/*
 * Converts from celcius to farenheit
 *
 */

double to_farenheit(int celcius) {
  return (celcius / (5.0 / 9.0)) - 32.0;
}

/*
 * Displays a conversion table between celcius and farenheit.
 *
 */

main() {
  int celcius;

  printf("%6s %8s\n", "celcius", "farenheit");

  for(celcius = 0; celcius <= UPPER; celcius += STEP) {
    printf("%6d %6.2f\n", celcius, to_farenheit(celcius));
  }
}
