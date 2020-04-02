#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../../include/crypto/base64.h"

size_t base64_decrypted_size(char *crtext)
{
	size_t len1;
	size_t lend;

	len1 = strlen(crtext);
	lend = len1/4*3;

	for(size_t i=len1; i-->0;)
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
	size_t len1, i, j, v;

	size_t outlen = base64_decrypted_size(crtext)+1;
	textout = malloc(outlen);

	len1 = strlen(crtext);

	for(i=0, j=0; i<len1; i+=4, j+=4)
	{
		v = base64inv[crtext[i]-43];
		v = (v << 6) | base64inv[crtext[i+1]-43];
		v = crtext[i+2] == '=' ? v << 6 : (v << 6) | base64inv[crtext[i+2]-43];
		v = crtext[i+3] == '=' ? v << 6 : (v << 6) | base64inv[crtext[i+3]-43];

		textout[j] = (v >> 16) & 0xFF;
		if(crtext[i+2] != '=')
			textout[j+1] = (v >> 8) & 0xFF;
		if(crtext[i+3] != '=')
			textout[j+2] = v & 0xFF;
	}
	return 1;
}


size_t base64_encrypted_size(size_t len)
{
	size_t ret;
	ret = len;

	if(len % 3 != 0)
		ret=ret+3 - (len%3);

	ret=ret/3;
	ret=ret*4;

	return ret;
}

char *base64(const unsigned char* text)
{
	size_t len = strlen(text);
	char *crtext;
	size_t elen, i,j ,v;

	elen = base64_encrypted_size(len);
	crtext = malloc(elen+1);
	crtext[elen] = '\0';
	
	for(i=0, j=0; i<len; i+=3, j+=4)
	{
		v = text[i];
		v = i+1 < len ? v << 8 | text[i+1] : v << 8;
		v = i+2 < len ? v << 8 | text[i+2] : v << 8;

		crtext[j] = base64al[(v >> 6) & 0x3F];
		crtext[j+1] = base64al[(v >> 12) & 0x3F];

		if(i+1 < len)
			crtext[j+2] = base64al[(v >> 6) & 0x3F];
		else
			crtext[j+2] = '=';

		if(i+2 < len)
			crtext[j+3] = base64al[v & 0x3F];
		else
			crtext[j+3] = '=';
	}
	return crtext;
}

void main() {
	char *text ="test";
	char *enc;
	enc = base64("yo");
	printf("%S",enc);
	printf("yo");
}
