#include <gmp.h>
#include <stdio.h>
#include <stdlib.h>
#include <gmpUtils.h>
#include <rsa.h>

void rsa_encrypt(unsigned long long int hexa_value, PUBLIC_KEY* public_key){
	
	mpz_t mpz_hexa_value;	mpz_init_set_ui(mpz_hexa_value, hexa_value);
	printf("%llX\n", hexa_value);

	/*
	mpz_powm(mpz_c, mpz_m, public_key->exponent, public_key->modulus);
	mpz_mod_ui(mpz_c_mod, mpz_c, 128);

	gmp_printf("mpz_c = %Zd\n", mpz_c);
	gmp_printf("mpz_c_mod = %Zd\n", mpz_c_mod);

	c = mpz_get_ui(mpz_c_mod);
	printf("c = <%c>", c );
	*/
}
