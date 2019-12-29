#include "headers/keyGen.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void getRandomNum(mpz_t rand_num, int rand_bit){
	
	mpz_t 		rand_bnd;
	gmp_randstate_t gmp_rand_state;

	mpz_init(rand_num);

	mpz_init_set_str(rand_bnd, "1000", 10);

	/* Define the default algorithm for random*/
	gmp_randinit_default(gmp_rand_state);
	
	/* 
	 * Getting seed random number, 
	 * The program is liable to be run more tha once per second, 
	 * and the system clock is too slow.
	 * So we are fetching a few bytes from /dev/urandom
	 */
	int s;
	long int seed;
	FILE *file;

	file = fopen("/dev/urandom", "rb");
	fread(&s, sizeof(long int), 1, file);
	fclose(file);
	srand(s);

	seed = rand();
	gmp_randseed_ui(gmp_rand_state, seed);

	mpz_urandomb(rand_num, gmp_rand_state, rand_bit);
	
		
}

void getRandomPrime(mpz_t rand_prime, int rand_bit){
	/* 
	 * Be sure that the probability that the number is a composite
	 * is extremly small, by checking the reps value.
	 * Reasonable values are between 15 and  50;
	 */
	int reps = 45;
	
	getRandomNum(rand_prime, rand_bit);
	
	/* 
	 * Determine if the number returned by getRandomNumber
	 * is a prime number with a probabilistic algorithm.
	 * 
	 * 2 is returned if the number is definitly prime,
	 * 1 is returned if the number is probably prime,
	 * 0 is returned if the number is definitly not prime.
	 */
	
	while(1){
		if(mpz_odd_p(rand_prime) == 1){
			//gmp_printf("%Zd\n",rand_prime);
			if(mpz_probab_prime_p(rand_prime, reps) < 1){
				getRandomNum(rand_prime, rand_bit);
			}
			else if(mpz_probab_prime_p(rand_prime, reps) >= 1){
				break;
			}
		}
		else{
			getRandomNum(rand_prime, rand_bit);
		}
	}
}
