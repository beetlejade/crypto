#include <gmp.h>
#include "header.h"

/*
 * gcd is a more convenient function for mpz_gcd,
 * that return the gcd value, if the value is to big to fit
 * an unsigned long, the function return the least significant
 * bites that do fit are returned.
 */ 

unsigned long gcd(mpz_t a, mpz_t b){
	mpz_t gcd_value;
	mpz_init(gcd_value);

	mpz_gcd(gcd_value, a, b);

	return mpz_get_ui(gcd_value);
}
