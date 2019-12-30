#ifndef _HEADER_H
#define _HEADER_H
#include <gmp.h>

void getRandomPrime(mpz_t rand_num, int rand_bit);
unsigned long gcd(mpz_t a, mpz_t b);
int coprimeNumber(mpz_t a, mpz_t b);

#endif
