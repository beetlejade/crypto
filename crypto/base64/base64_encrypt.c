#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

const char base64al[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

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
	size_t elen, i, j, v;

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
	char *test = "test";
	char *enc;
	enc = base64(test);
	printf("%s", enc);
}
