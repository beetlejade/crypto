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

void rsa_keyGen(struct PUBLIC_KEY*, struct PRIVATE_KEY*, int size);
void rsa_encryption();

#endif
