#include "stdio.h"
#include "math.h"
#include "stdbool.h"

#ifndef MAX_EXPO
#define MAX_EXPO 8
#endif

static const int primes[MAX_EXPO] = { 2, 3, 5, 7, 11, 13, 17, 19 };

int main(int argc, char const *argv[])
{
  int k = 20, i = 0;
  int exponents[MAX_EXPO] = { 0 };
  long long N = 1;

  for (i = 0; i < MAX_EXPO; ++i)
    {
      double res;
      exponents[i] = (int)floor(log(k) / log(primes[i]));
      res = pow((double)primes[i], (double)exponents[i]);
      N = N * (long long)res;
    }
  printf("%lld\n", N);
  for (i = 0; i < MAX_EXPO; ++i)
    {
      printf("%d\n", exponents[i]);
    }

  return 0;
}
