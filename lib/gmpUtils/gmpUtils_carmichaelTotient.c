#include <gmp.h>
#include <gmpUtils.h>

/* 
 * Compute the Euler totient of n, that is (p-1)(q-1),
 * with n = pq.
 */  

void gmpUtils_carmichaelTotient(mpz_t euler_totient, mpz_t p, mpz_t q){
	mpz_t p_minus_one, q_minus_one;

	mpz_init(p_minus_one);
	mpz_init(q_minus_one);

	mpz_sub_ui(p_minus_one, p, 1);
	mpz_sub_ui(q_minus_one, q, 1);

	mpz_lcm(euler_totient, p_minus_one, q_minus_one);

}
