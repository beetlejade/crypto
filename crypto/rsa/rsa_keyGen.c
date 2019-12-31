#include <gmp.h>
#include <stdio.h>
#include <stdlib.h>
#include <gmpUtils.h>

void rsa_keyGen(mpz_t private, mpz_t public, int size){

	printf("Generating keys...\n");
	printf("[                                        ]");
	
	mpz_t p,q;
	mpz_init(p);
	mpz_init(q);

	gmpUtils_getRandomPrime(p, 128);
	gmpUtils_getRandomPrime(q, 128);


}

