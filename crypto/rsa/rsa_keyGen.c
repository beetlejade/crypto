#include <gmp.h>
#include <stdio.h>
#include <stdlib.h>
#include <gmpUtils.h>
#include <rsa.h>

void rsa_keyGen(mpz_t private_key, mpz_t public_key, int size){

	printf("Generating keys...\n");
	printf("[                                        ]");
	
	mpz_t p,q;
	mpz_init(p);
	mpz_init(q);

	gmpUtils_getRandomPrime(p, 128);
	gmpUtils_getRandomPrime(q, 128);


}

