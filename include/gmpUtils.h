#ifndef _GMPUTILS_H
#define _GMPUTILS_H
#include <gmp.h>

void gmpUtils_getRandomPrime(mpz_t rand_num, int rand_bit);
void gmpUtils_eulerTotient(mpz_t euler_totient, mpz_t p, mpz_t q);
unsigned long gmpUtils_gcd(mpz_t a, mpz_t b);
int gmpUtils_coprimeNumber(mpz_t a, mpz_t b);

#endif
