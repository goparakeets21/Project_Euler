#include "stdio.h"
#include "stdint.h"
#include "inttypes.h"

static uint64_t grid[21][21] = { { 0u } };

uint64_t numberOfPaths(int x, int y)
{
  int i;
  int j;

  // All paths for the first row and column is 1
  for (i = 0; i < x; i++)
    {
      grid[i][0] = 1;
      grid[0][i] = 1;
    }

  // Iterate over the table and gradually build up paths based on previous
  // solutions
  for (i = 1; i < x; i++)
    {
      for (j = 1; j < y; j++)
        {
          //each vertex is the sum of the adjacent two
          grid[i][j] = grid[i - 1][j] + grid[i][j - 1];
        }
    }
  return grid[x - 1][y - 1];
}

int main(int argc, char const *argv[])
{
  uint64_t res;

  res = numberOfPaths(21, 21);

  printf("%" PRIu64 "\n", res);
  return 0;
}
