#include "stdbool.h"
#include "stdio.h"
#include "string.h"

#ifndef MAX_INT
#define MAX_INT 775147u
#endif

#ifndef NUM_TO_CHECK
#define NUM_TO_CHECK 600851475143ull
#endif

static bool prime[MAX_INT] = {true};

void SieveOfEratosthenes(void);

int main(int argc, char const *argv[]) {
  long long i;
  SieveOfEratosthenes();

  for(i = MAX_INT-1; i >= 0; i--) {
    if(prime[i] == true) {
      if(NUM_TO_CHECK % i == 0) {
        printf("%lld\n", i);
        break;
      }
    }
  }

  return 0;
}

void SieveOfEratosthenes(void) {
  int p, i;
  memset(prime, true, sizeof(prime));

  for (p=2; p*p<=MAX_INT; p++)
    {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true)
        {
            // Update all multiples of p
            for (i=p*2; i<=MAX_INT; i += p)
                prime[i] = false;
        }
    }
}
