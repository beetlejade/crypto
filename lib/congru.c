#include "mathUtils.h"

int congru(int a, int b, int n){
	if(a % n == b % n){
		return 1;
	}

	return 0;
}

