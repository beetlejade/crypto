#include <gmp.h>
#include <stdio.h>
#include <stdlib.h>
#include <gmpUtils.h>
#include <rsa.h>

void rsa_keyGen(mpz_t private_key, mpz_t public_key, int size){
	printf("Generating keys...\n");

	mpz_t p;	mpz_init(p);
	mpz_t q;	mpz_init(q);
	mpz_t n;	mpz_init(n);
	mpz_t lambdaN;	mpz_init(lambdaN);
	mpz_t e;	
	mpz_t d;	mpz_init(d);

	gmpUtils_getRandomPrime(p, size);
	gmpUtils_getRandomPrime(q, size);
 	gmp_printf("p = %Zd\n", p);
	gmp_printf("q = %Zd\n", q);

	mpz_mul(n, p, q);
	gmp_printf("n = %Zd\n", n);

	gmpUtils_eulerTotient(lambdaN, p, q);
	gmp_printf("lambda(n) = %Zd\n", lambdaN);
	
	/* We take the most commonly used value for e, 2^16 + 1 = 65537 */
	mpz_init_set_str(e, "65537", 10);
	gmp_printf("e = %Zd\n", e);
	
	mpz_t gcd;	mpz_init(gcd);
	mpz_t u;	mpz_init(u);
	
	/* 
	 * Compute u and d to satisfy n*u + e*d = gcd(n, e).
	 * Here we whant to compute d, with d*e congru 1 mod n.
	 */
	mpz_gcdext(gcd, u, d, n, e);
	mpz_abs(d, d);
	gmp_printf("d = %Zd\n", d);

	gmp_printf("\nPublic modulus   : %Zd\n", n);
	gmp_printf("Public exponent  : %Zd\n", e);
	gmp_printf("Private exponent : %Zd\n", d);

}
