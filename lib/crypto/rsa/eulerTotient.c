#include <gmp.h>
#include "headers/keyGen.h"

/* 
 * Compute the Euler totient of n, that is (p-1)(q-1),
 * with n = pq.
 */  

void eulerTotient(mpz_t euler_totient, mpz_t p, mpz_t q){
	mpz_t p_minus_one, q_minus_one;
	mpz_t negative_one;

	mpz_init_set_str(negative_one, "-1", 10);
	mpz_init(p_minus_one);
	mpz_init(q_minus_one);

	mpz_add(p_minus_one, p, negative_one);
	mpz_add(q_minus_one, q, negative_one);
	mpz_mul(euler_totient, p_minus_one, q_minus_one);
}
