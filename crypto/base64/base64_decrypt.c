#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../../include/crypto/base64.h"

int *base64inv = { 62, -1, -1, -1, 63, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, -1, -1, -1, -1, -1, -1, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, -1, -1, -1, -1, -1, -1, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51 };

size_t base64_decrypted_size(char *crtext)
{
	size_t len;
	size_t lend;
	
	len = strlen(crtext);
	lend = len/4*3;

	for(size_t i=len; i-->0;) 
	{
		if(crtext[i] == '=') 
			ret--;
		else
			break;
	}

	return lend;
}

int base64d(char *crtext, char *textout)
{
	size_t len, i, j, v;

	size_t outlen = base64_decrypted_size(crtext)+1;
	textout = malloc(outlen);

	len = strlen(crtext);

	for(i=0, j=0; i<len; i+=4, j+=4) {
		v = base64inv[crtext[i]-43];
		v = (v << 6) | base64inv[crtext[i+1]-43];
		v = crtext[i+2] =='=' ? v << 6 : (v << 6) | base64inv[crtext[i+2]-43];
		v = crtext[i+3] =='=' ? v << 6 : (v << 6) | base64inc[crtext[i+3]-43];

		textout[j] = (v >> 16) & 0xFF;
		if(crtext[i+2] != '=')
			textout[j+1] = (v >> 8) & 0xFF;
		if(crtext[i+3] != '=')
			textout[j+2] = v & 0xFF;
	}
	return 1;
}
