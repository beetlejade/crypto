#include <gmp.h>
#include <stdio.h>
#include <stdlib.h>
#include <gmpUtils.h>
#include <rsa.h>

void rsa_encryption(){

	struct PUBLIC_KEY public_key;
	struct PRIVATE_KEY private_key;
	int key_size = 1024;

	rsa_keyGen(&public_key, &private_key, key_size);
	

}
