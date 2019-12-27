#include "mathUtils.h"
#include <stdio.h>

int main(void){

	printf("is 7655654 a prime number ? %d\n", prime(7655654));	
	printf(">%d\n", congru(5, 6, 2));
	printf("gcd of 12 and 7 is %d\n", gcd(12, 7));
	printf("12 and 7 are comprime numbers ? : %d\n", comprimeNumbers(6, 13));
	return 0;
}
