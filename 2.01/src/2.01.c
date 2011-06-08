#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {

  // chars: signed

  printf("unsigned char is between %d and %d\n", 0, UCHAR_MAX);

  // chars: unsigned

  printf("signed char is between %d and %d\n", SCHAR_MIN, SCHAR_MAX);

  // ints: unsigned

  printf("unsigned short int is between %i and %i\n", 0, USHRT_MAX);
  printf("unsigned int is between %i and %ui\n", 0, UINT_MAX);
  printf("unsigned long int is between %i and %lui\n", 0, ULONG_MAX);

  // ints: signed

  printf("signed short int is between %i and %i\n", SHRT_MIN, SHRT_MAX);
  printf("signed int is between %i and %i\n", INT_MIN, INT_MAX);
  printf("signed long int is between %li and %li\n", LONG_MIN, LONG_MAX);

  // floats

  printf("float is between %f and %f\n", FLT_MIN, FLT_MAX);
  printf("double is between %f and %f\n", DBL_MIN, DBL_MAX);
  printf("long double is between %Lf and %Lf\n", LDBL_MIN, LDBL_MAX);

  return 0;
}
