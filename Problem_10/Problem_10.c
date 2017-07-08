#include "stdio.h"
#include "stdbool.h"
#include "string.h"
#include "stdint.h"
#include "inttypes.h"

#ifndef MAX_INT
#define MAX_INT 2000000u
#endif

static bool prime[MAX_INT] = { true };

void SieveOfEratosthenes(void);

void SieveOfEratosthenes(void)
{
  uint64_t p, i;

  memset(prime, true, sizeof(prime));

  prime[0] = false;
  prime[1] = false;

  for (p = 2; p * p <= MAX_INT; p++)
    {
      // If prime[p] is not changed, then it is a prime
      if (prime[p] == true)
        {
          // Update all multiples of p
          for (i = p * 2; i <= MAX_INT; i += p)
            prime[i] = false;
        }
    }
}

int main(int argc, char const *argv[])
{
  uint64_t sum = 0u;
  uint32_t i;

  SieveOfEratosthenes();

  for (i = 0u; i < MAX_INT; ++i)
    {
      if (prime[i] == true)
        {
          sum += i;
        }
    }

  printf("%" PRIu64 "\n", sum);

  return 0;
}
