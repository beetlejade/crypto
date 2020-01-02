#include <stdio.h>
#include <gmp.h>
#include <gmpUtils.h>

#include <rsa.h>

int  main(void){
	
	PUBLIC_KEY public_key;
	PRIVATE_KEY private_key;
	int key_size = 512;

	rsa_keyGen(&public_key, &private_key, key_size);
	rsa_encrypt(0x64E, &public_key);

	return 0;
}
