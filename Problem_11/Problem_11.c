#include "stdio.h"
#include "stdint.h"
#include "stdbool.h"
#include "inttypes.h"

uint32_t grid[20][20] = {
  { 8u, 2u, 22u, 97u, 38u, 15u, 0u, 40u, 0u, 75u, 4u, 5u, 7u, 78u, 52u, 12u, 50u, 77u, 91u, 8u },
  { 49u, 49u, 99u, 40u, 17u, 81u, 18u, 57u, 60u, 87u, 17u, 40u, 98u, 43u, 69u, 48u, 04u, 56u, 62u, 0u },
  { 81u, 49u, 31u, 73u, 55u, 79u, 14u, 29u, 93u, 71u, 40u, 67u, 53u, 88u, 30u, 3u, 49u, 13u, 36u, 65u },
  { 52u, 70u, 95u, 23u, 4u, 60u, 11u, 42u, 69u, 24u, 68u, 56u, 1u, 32u, 56u, 71u, 37u, 2u, 36u, 91u },
  { 22u, 31u, 16u, 71u, 51u, 67u, 63u, 89u, 41u, 92u, 36u, 54u, 22u, 40u, 40u, 28u, 66u, 33u, 13u, 80u },
  { 24u, 47u, 32u, 60u, 99u, 3u, 45u, 02u, 44u, 75u, 33u, 53u, 78u, 36u, 84u, 20u, 35u, 17u, 12u, 50u },
  { 32u, 98u, 81u, 28u, 64u, 23u, 67u, 10u, 26u, 38u, 40u, 67u, 59u, 54u, 70u, 66u, 18u, 38u, 64u, 70u },
  { 67u, 26u, 20u, 68u, 02u, 62u, 12u, 20u, 95u, 63u, 94u, 39u, 63u, 8u, 40u, 91u, 66u, 49u, 94u, 21u },
  { 24u, 55u, 58u, 5u, 66u, 73u, 99u, 26u, 97u, 17u, 78u, 78u, 96u, 83u, 14u, 88u, 34u, 89u, 63u, 72u },
  { 21u, 36u, 23u, 9u, 75u, 0u, 76u, 44u, 20u, 45u, 35u, 14u, 0u, 61u, 33u, 97u, 34u, 31u, 33u, 95u },
  { 78u, 17u, 53u, 28u, 22u, 75u, 31u, 67u, 15u, 94u, 3u, 80u, 04u, 62u, 16u, 14u, 9u, 53u, 56u, 92u },
  { 16u, 39u, 5u, 42u, 96u, 35u, 31u, 47u, 55u, 58u, 88u, 24u, 0u, 17u, 54u, 24u, 36u, 29u, 85u, 57u },
  { 86u, 56u, 0u, 48u, 35u, 71u, 89u, 07u, 05u, 44u, 44u, 37u, 44u, 60u, 21u, 58u, 51u, 54u, 17u, 58u },
  { 19u, 80u, 81u, 68u, 5u, 94u, 47u, 69u, 28u, 73u, 92u, 13u, 86u, 52u, 17u, 77u, 4u, 89u, 55u, 40u },
  { 04u, 52u, 8u, 83u, 97u, 35u, 99u, 16u, 7u, 97u, 57u, 32u, 16u, 26u, 26u, 79u, 33u, 27u, 98u, 66u },
  { 88u, 36u, 68u, 87u, 57u, 62u, 20u, 72u, 3u, 46u, 33u, 67u, 46u, 55u, 12u, 32u, 63u, 93u, 53u, 69u },
  { 4u, 42u, 16u, 73u, 38u, 25u, 39u, 11u, 24u, 94u, 72u, 18u, 8u, 46u, 29u, 32u, 40u, 62u, 76u, 36u },
  { 20u, 69u, 36u, 41u, 72u, 30u, 23u, 88u, 34u, 62u, 99u, 69u, 82u, 67u, 59u, 85u, 74u, 4u, 36u, 16u },
  { 20u, 73u, 35u, 29u, 78u, 31u, 90u, 1u, 74u, 31u, 49u, 71u, 48u, 86u, 81u, 16u, 23u, 57u, 05u, 54u },
  { 1u, 70u, 54u, 71u, 83u, 51u, 54u, 69u, 16u, 92u, 33u, 48u, 61u, 43u, 52u, 1u, 89u, 19u, 67u, 48u }
};

typedef enum directions {
  UP_LEFT,
  UP,
  UP_RIGHT,
  RIGHT,
  DOWN_RIGHT,
  DOWN,
  DOWN_LEFT,
  LEFT,
  DIR_MAX
} Direction;

bool checkDirection(uint64_t x, uint64_t y, Direction d);

uint64_t computeMaxProduct(uint64_t x, uint64_t y);


/**
 * Function to check that ensure we don't run off the ends of the arrays
 * @param  x [X index]
 * @param  y [Y index]
 * @param  d [enum direction we are traveling in]
 * @return   [true if direction is valid, false if not]
 */
bool checkDirection(uint64_t x, uint64_t y, Direction d)
{
  switch (d)
    {
    case UP_LEFT:
      if ((x < 3) || (y < 3))
        {
          return false;
        }
      break;

    case UP:
      if (x < 3)
        {
          return false;
        }
      break;

    case UP_RIGHT:
      if ((x < 3) || (y > 16))
        {
          return false;
        }
      break;

    case RIGHT:
      if (y > 16)
        {
          return false;
        }
      break;

    case DOWN_RIGHT:
      if ((y > 16) || (x > 16))
        {
          return false;
        }
      break;

    case DOWN:
      if (x > 16)
        {
          return false;
        }
      break;

    case DOWN_LEFT:
      if ((x > 16) || (y < 3))
        {
          return false;
        }
      break;

    case LEFT:
      if (y < 3)
        {
          return false;
        }
      break;

    default:
      return false;
      break;
    }
  return true;
}

uint64_t computeMaxProduct(uint64_t x, uint64_t y)
{
  uint64_t product = 0u;

  //Don't waste time commuting if its obviously 0
  if (grid[x][y] == 0u)
    {
      return 0u;
    }

  if (true == checkDirection(x, y, UP_LEFT))
    {
      uint64_t temp = grid[x][y] * grid[x - 1][y - 1] * \
                      grid[x - 2][y - 2] * grid[x - 3][y - 3];
      product = (product > temp) ? product : temp;
    }
  if (true == checkDirection(x, y, UP))
    {
      uint64_t temp = grid[x][y] * grid[x - 1][y] * \
                      grid[x - 2][y] * grid[x - 3][y];
      product = (product > temp) ? product : temp;
    }
  if (true == checkDirection(x, y, UP_RIGHT))
    {
      uint64_t temp = grid[x][y] * grid[x - 1][y + 1] * \
                      grid[x - 2][y + 2] * grid[x - 3][y + 3];
      product = (product > temp) ? product : temp;
    }
  if (true == checkDirection(x, y, RIGHT))
    {
      uint64_t temp = grid[x][y] * grid[x][y + 1] * \
                      grid[x][y + 2] * grid[x][y + 3];
      product = (product > temp) ? product : temp;
    }
  if (true == checkDirection(x, y, DOWN_RIGHT))
    {
      uint64_t temp = grid[x][y] * grid[x + 1][y + 1] * \
                      grid[x + 2][y + 2] * grid[x + 3][y + 3];
      product = (product > temp) ? product : temp;
    }
  if (true == checkDirection(x, y, DOWN))
    {
      uint64_t temp = grid[x][y] * grid[x + 1][y] * \
                      grid[x + 2][y] * grid[x + 3][y];
      product = (product > temp) ? product : temp;
    }
  if (true == checkDirection(x, y, DOWN_LEFT))
    {
      uint64_t temp = grid[x][y] * grid[x + 1][y - 1] * \
                      grid[x + 2][y - 2] * grid[x + 3][y - 3];
      product = (product > temp) ? product : temp;
    }
  if (true == checkDirection(x, y, LEFT))
    {
      uint64_t temp = grid[x][y] * grid[x][y - 1] * \
                      grid[x][y - 2] * grid[x][y - 3];
      product = (product > temp) ? product : temp;
    }

  return product;
}

int main(int argc, char const *argv[])
{
  uint64_t max_product = 0u;
  uint64_t i;
  uint64_t j;

  for (i = 0; i < 20; ++i)
    {
      for (j = 0; j < 20; ++j)
        {
          uint64_t temp;
          temp = computeMaxProduct(i, j);
          max_product = (max_product > temp) ? max_product : temp;
        }
    }

  printf("%" PRIu64 "\n", max_product);
  return 0;
}
