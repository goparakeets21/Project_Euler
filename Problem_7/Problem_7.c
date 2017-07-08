#include "stdio.h"
#include "stdbool.h"

#ifndef PRIME_LIMIT
#define PRIME_LIMIT 10001
#endif


/**
 * Function to check if a number is prime.  Number must be prime if it not
 * evenly divisible by numbers less than or equal to the floor of the square
 * root of the number.  Since square root is a costly operation, checking
 * for the number squared is more than sufficient.
 * @param  n an unsigned integer which we want to check if it is prime.
 * @return   true if the number is prime
 */
bool isPrime(unsigned int n) {
  unsigned int i;
  for( i=2u; i*i<=n; i++) {
    if(n % i == 0){
      return false;
    }
  }
  return true;
}

int main(int argc, char const *argv[]) {
  unsigned int count = 1;  //2 is prime, first number checked is 3
  unsigned int candidate = 1;

  //iterate until we reach the 10001st prime
  while(count < limit) {
    candidate += 2; //skip evens
    if(true == isPrime(candidate)) {
      count++;
    }
  }

  printf("%lld\n", candidate);
  return 0;
}
