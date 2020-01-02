#include <stdio.h>
#include <gmp.h>
#include <gmpUtils.h>

#include <rsa.h>

int  main(void){
	printf("Main program !\n");
	 
	mpz_t private_key, public_key;
	mpz_init(private_key);
	mpz_init(public_key);
	int key_size = 128;


	rsa_keyGen(private_key, public_key, key_size);

	return 0;
}
