#include <gmp.h>
#include <stdio.h>
#include <gmpUtils.h>

int gmpUtils_coprimeNumber(mpz_t a, mpz_t b){
	mpz_t gcd_value;
	mpz_init(gcd_value);

	mpz_gcd(gcd_value, a, b);

	/* Checking if gcd_value is equal to 1 */
	if(mpz_get_ui(gcd_value) == 1){
		return 1;
	}

	return 0;
}
