#include "mathUtils.h"

int prime(int a){
	if(a<=1) { return FALSE; }
	if(a<=3) { return TRUE; }
	if(n%2==0 || n%3 ==0 ) { return FALSE; }
	
	int i = 5;
	while(i*i<=n) {
		if(n%i==0 || n%(i+2)==0) { return FALSE; }
		i = i +6;
	}
	return TRUE;

