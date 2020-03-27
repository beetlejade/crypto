#ifndef _BASE64_H
#define _BASE64_H

const char *base64al = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

size_t base64_encrypted_size(size_t len);
char *base64(const unsigned char *text);

size_t base64_decrypted_size(char *crtext);
int base64d(char *crtextin, char *clrtextout);

#endif
