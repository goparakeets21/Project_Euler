#include "gmp.h"
#include "stdio.h"

int main(int argc, char const *argv[])
{
    mpz_t             res;
    unsigned long int power = 1000ul;
    unsigned long int base  = 2ul;
    mpz_t             sum;
    mpz_t             scratch;

    // Init the variables
    mpz_init(res);
    mpz_init(sum);
    mpz_init(scratch);

    mpz_ui_pow_ui(res, base, power);

    while (0 != mpz_cmp_ui(res, 0ul))
    {
        mpz_fdiv_qr_ui(res, scratch, res, 10ul);
        mpz_add(sum, sum, scratch);
    }

    gmp_printf("%Zd\n", sum);
    return 0;
}
