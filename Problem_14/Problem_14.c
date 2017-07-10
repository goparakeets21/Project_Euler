#include "stdio.h"
#include "stdint.h"
#include "inttypes.h"
#include "string.h"

#ifndef MAX_COLLATZ
#define MAX_COLLATZ (1000000u)
#endif

static uint64_t nums[MAX_COLLATZ] = { 0u };

uint64_t PerformCollatz(uint64_t n)
{
  uint64_t count = 0ul;

  while (n != 1ul)
    {
      if ((n < MAX_COLLATZ) && (nums[n] != 0))
        {
          return count + nums[n];
        }

      if ((n % 2) == 0)
        {
          n >>= 1;
        }
      else
        {
          n = 3 * n + 1;
        }
      count++;
    }
  return count;
}

int main(int argc, char const *argv[])
{
  uint64_t i = 0ul;
  uint64_t max = 0ul;

  memset(&nums, 0, sizeof(*nums));

  for (i = 1ul; i < MAX_COLLATZ; ++i)
    {
      nums[i] = PerformCollatz(i);
    }

  for (i = 0; i < MAX_COLLATZ; ++i)
    {
      max = (nums[max] < nums[i]) ? i : max;
    }

  printf("%" PRIu64 "\n", max);
  return 0;
}
