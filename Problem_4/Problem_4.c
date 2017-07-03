#include "stdio.h"
#include "stdbool.h"
#include "string.h"

static int products[999*999] = {0u};

/**
 * Function to determine if an integer is a palindrome.
 * @param  num An integer, must be as the output may overflow.  However not in
 * this case
 * @return     an integer, 1 for true, 0 for false
 */
int isNumberPalindrome(int num) {
  int n = num, rev = 0;;

  while (n > 0) {
    int dig = n % 10;
    rev = (rev * 10) + dig;
    n /= 10;
  }

  if(rev == num) {
    return 1;
  } else {
    return 0;
  }
}

/**
 * Main driver
 * @param  argc unused
 * @param  argv unused
 * @return      0 for default
 */
int main(int argc, char const *argv[]) {
  int i, j;
  memset(products, -1, sizeof(products));
  for(i = 999; i > 0; --i) {
    for(j = 999; j > 0; --j) {
      int product = i*j;
      if(0 == products[product]) {
        continue;
      } else {
        products[product] = isNumberPalindrome(product);
      }
    }
  }

  for(i = 999*999; i >= 0; --i) {
    if(1 == products[i]) {
      printf("%d\n", i);
      break;
    }
  }
  return 0;
}
