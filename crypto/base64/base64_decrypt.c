#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../../include/crypto/base64.h"

size_t base64_decrypted_size(char *crtext)
{
	size_t len;
	size_t lend;
	
	len = strlen(crtext);
	lend = len/4*3;

	for(size_t i=len; i-->0;) 
	{
		if(crtext[i] == '=') 
			lend--;
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
		v = crtext[i+3] =='=' ? v << 6 : (v << 6) | base64inv[crtext[i+3]-43];

		textout[j] = (v >> 16) & 0xFF;
		if(crtext[i+2] != '=')
			textout[j+1] = (v >> 8) & 0xFF;
		if(crtext[i+3] != '=')
			textout[j+2] = v & 0xFF;
	}
	return 1;
}
