#include "math.h"
#include "stdio.h"

#ifndef MAX_NUM
#define MAX_NUM 100
#endif

long long sumOfSquares(int N);

long long squareOfSum(int N);

long long sumOfSquares(int N) {
    return N * (N+1) * (2*N + 1) / 6;
}

long long squareOfSum(int N) {
    int sum = N * (N+1) >> 1;
    return (long long)pow((double)sum, 2.0f);
}

int main(int argc, char const *argv[]) {
    long long sumSquare, squareSum;

    sumSquare = sumOfSquares(MAX_NUM);
    squareSum = squareOfSum(MAX_NUM);
    printf("%lld\n", squareSum - sumSquare);
    return 0;
}
