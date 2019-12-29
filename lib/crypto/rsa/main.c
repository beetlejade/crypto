#include <stdio.h>
#include <gmp.h>
#include "headers/keyGen.h"
#include <stdlib.h>
#include <stdarg.h>


void main(void){
	mpz_t num;
	int size = 512;
	getRandomPrime(num, size);
	gmp_printf("Random number of %d bits : %Zd\n", size, num);
}
