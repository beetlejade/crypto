#include <gmp.h>
#include <stdio.h>
#include <stdlib.h>
#include <gmpUtils.h>
#include <rsa.h>

void rsa_decrypt(mpz_t* M, mpz_t C, PRIVATE_KEY* private_key){
	
	mpz_powm(*M, C, private_key->exponent, private_key->modulus);
}
