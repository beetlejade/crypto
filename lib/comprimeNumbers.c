#include "mathUtils.h"

int comprimeNumbers(int a, int b){
	if(gcd(a, b) == 1){
		return 1;
	}

	return 0;
}
