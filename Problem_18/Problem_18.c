#include "stdio.h"
#include "stdlib.h"

typedef struct smartArray
{
    int    * arr;
    size_t size;
} smartArray;

#ifndef NUM_ROWS
#define NUM_ROWS    15
#endif

#ifndef NUM_ELEMENTS
#define NUM_ELEMENTS    ((NUM_ROWS * (NUM_ROWS + 1)) / 2)
#endif

char nums[] = "75 "
              "95 64 "
              "17 47 82 "
              "18 35 87 10 "
              "20 04 82 47 65 "
              "19 01 23 75 03 34 "
              "88 02 77 73 07 63 67 "
              "99 65 04 28 06 16 70 92 "
              "41 41 26 56 83 40 80 70 33 "
              "41 48 72 33 47 32 37 16 94 29 "
              "53 71 44 65 25 43 91 52 97 51 14 "
              "70 11 33 28 77 73 17 78 39 68 17 57 "
              "91 71 52 38 17 14 91 43 58 50 27 29 48 "
              "63 66 04 68 89 53 67 30 73 16 69 87 40 31 "
              "04 62 98 27 23 09 70 98 73 93 38 53 60 04 23";

int num[NUM_ELEMENTS] = { 0 };

int maxPathTriangle(void)
{
    int row = NUM_ROWS;
    int i   = 0;
    int c;
    int bytes;
    char* input;

    input = nums;

    //Parse the string, extracting the numbers out
    while (sscanf(input, "%d%n", &c, &bytes) > 0)
    {
        num[i++] = c;
        input   += bytes;
    }

    //Iterate over the rows
    for (row = NUM_ROWS - 1; row > 0; row--)
    {
        int start = (row * (row - 1) / 2);
        int end   = ((row - 1) * (row + 2) / 2);
        int j;

        //For each element in each row, take the max
        for (j = start; j <= end; j++)
        {
            num[j] += (num[j + row] > num[j + row + 1]) ? \
                      num[j + row]  : num[j + row + 1];
        }
    }

    //return the last element (max)
    return num[0];;
}

int main(int argc, char const *argv[])
{
    int max = maxPathTriangle();

    printf("%d\n", max);
    return 0;
}
