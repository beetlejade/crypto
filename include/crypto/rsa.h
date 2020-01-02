#ifndef _RSA_H
#define _RSA_H

typedef struct PUBLIC_KEY{
	mpz_t modulus;
	mpz_t exponent;
}PUBLIC_KEY;

typedef struct PRIVATE_KEY{
	mpz_t modulus;
	mpz_t exponent;
}PRIVATE_KEY;

void rsa_keyGen(struct PUBLIC_KEY* public_key, struct PRIVATE_KEY* private_key, int size);
void rsa_encrypt(unsigned long long int hexa_value, PUBLIC_KEY* public_key);

#endif
