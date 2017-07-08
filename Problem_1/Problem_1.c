#include "stdio.h"

#ifndef LIMIT
#define LIMIT (999u)
#endif

int arithSeq(int a);

int arithSum(int a);

int main(int argc, char const *argv[])
{
  int sum = arithSeq(LIMIT);

  printf("%d\n", sum);;
  return 0;
}

int arithSeq(int a)
{
  int sum = 0;

  sum += 3 * arithSum(a / 3);
  sum += 5 * arithSum(a / 5);
  sum -= 15 * arithSum(a / 15);

  return sum;
}

int arithSum(int a)
{
  return((a * (a + 1)) >> 1);
}
