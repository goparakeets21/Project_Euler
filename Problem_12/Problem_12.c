#include "stdio.h"
#include "stdint.h"
#include "inttypes.h"

uint32_t countDivisors(uint64_t n)
{
  uint32_t i = 0;
  uint32_t count = 0;

  for (i = 1; i * i <= n; ++i)
    {
      if (n % i == 0)
        {
          if (n / i == i)
            {
              count++;
            }
          else
            {
              count += 2;
            }
        }
    }
  return count;
}

int main(int argc, char const *argv[])
{
  uint32_t count = 0;
  uint32_t i = 0;
  uint64_t triangle = 0;

  while (count < 500)
    {
      i++;
      triangle += i;
      count = countDivisors(triangle);
    }

  printf("%" PRIu64 "\n", triangle);
  return 0;
}
