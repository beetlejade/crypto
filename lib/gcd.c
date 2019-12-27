#include "mathUtils.h"

int gcd(int a, int b){
	if(b){
		return gcd(b, a % b);
	}
	else{
		return a;
	}
}
