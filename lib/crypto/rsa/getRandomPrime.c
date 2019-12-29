#include "headers/keyGen.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void getRandomPrime(mpz_t rand_num, int rand_bit){
	
	mpz_t 		rand_bnd;
	int 		seed;
	gmp_randstate_t gmp_rand_state;

	mpz_init(rand_num);

	mpz_init_set_str(rand_bnd, "1000", 10);

	/* Define the default algorithm for random*/
	gmp_randinit_default(gmp_rand_state);
	/* Get the seed for generation */
	srand(time(NULL));
	seed = rand();
	gmp_randseed_ui(gmp_rand_state, seed);

	mpz_urandomb(rand_num, gmp_rand_state, rand_bit);
	
}
