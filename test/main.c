#include <stdio.h>
#include <gmp.h>
#include "headers/keyGen.h"
#include <gmpUtils.h>
#include <stdlib.h>
#include <stdarg.h>


void main(void){
	mpz_t num1;
	mpz_t num2;
	mpz_t n;
	mpz_t euler_totient;
	int size = 16;
	
	mpz_init(n);
	mpz_init(euler_totient);

	getRandomPrime(num1, size);
	getRandomPrime(num2, size);
	gmp_printf("num1 : %Zd\n", num1);
	gmp_printf("num2 : %Zd\n\n", num2);

	mpz_t a, b;
	mpz_init_set_str(a, "40", 10);
	mpz_init_set_str(b, "25", 10);


	printf("The gcd of 40 and 23 is %d\n",gcd(a, b));
	printf("%d\n",coprimeNumber(a, b));
	
	mpz_mul(n, num1, num2);
	gmp_printf("n = %Zd\n\n", n);
	eulerTotient(euler_totient, num1, num2);
	
	gmp_printf("The Euler totient of n is %Zd\n",euler_totient);
}
