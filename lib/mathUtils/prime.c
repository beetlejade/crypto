#include "mathUtils.h"

int prime(int a){
	if(a<=1) { return 0; }
	if(a<=3) { return 1; }
	if(a%2==0 || a%3 ==0 ) { return 0; }
	
	int i = 5;
	while(i*i<=a) {
		if(a%i==0 || a%(i+2)==0) { return 0; }
		i+=6;
	} return 1;
}
