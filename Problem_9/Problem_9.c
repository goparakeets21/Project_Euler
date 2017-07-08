#include "stdio.h"
#include "stdbool.h"

bool checkPythagoreanTriplet(int a, int b, int c);

bool checkPythagoreanTriplet(int a, int b, int c)
{
  if ((a * a) + (b * b) == (c * c))
    {
      return true;
    }
  else
    {
      return false;
    }
}

int main(int argc, char const *argv[])
{
  int i;
  int j;
  int k;

  for (i = 1; i < 1000; i++)
    {
      for (j = i; j < (1000 - i); j++)
        {
          for (k = j; k < (1000 - j); k++)
            {
              if (checkPythagoreanTriplet(i, j, k) && (i + j + k) == 1000)
                {
                  printf("%d %d %d\n", i, j, k);
                  printf("%d\n", (i * j * k));
                  break;
                }
            }
        }
    }
  return 0;
}
