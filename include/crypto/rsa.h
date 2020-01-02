#ifndef _RSA_H
#define _RSA_H

struct PUBLIC_KEY{
	mpz_t modulus;
	mpz_t exponent;
};

struct PRIVATE_KEY{
	mpz_t modulus;
	mpz_t exponent;
};

void rsa_keyGen(mpz_t private_key, mpz_t public_key, int size);
//int rsa_keyCheck(mpz_t public_modulus, mpz_t public_exponent, mpz_t private_exponent);
void rsa_encryption();

#endif
