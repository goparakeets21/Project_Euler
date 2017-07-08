#include "stdio.h"

static int fibNums[34] = { 0 };

int fibbonaci(int x);

int main(int argc, char const *argv[])
{
  int i = 0, sum = 0;

  fibNums[0] = 1;
  fibNums[1] = 1;
  (void)fibbonaci(33);

  for (i = 2; i < 34; i += 3)
    {
      sum += fibNums[i];
    }

  printf("%d\n", sum);
  return 0;
}

int fibbonaci(int x)
{
  if (x == 0)
    return 1;
  if (x == 1)
    return 1;
  if (fibNums[x] != 0)
    return fibNums[x];

  fibNums[x] = fibbonaci(x - 1) + fibbonaci(x - 2);

  return fibNums[x];
}
