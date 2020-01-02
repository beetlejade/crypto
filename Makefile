CC = gcc
CFLAGS = -Wall -lgmp
NAME = main
EXEC = main

# Include flags
INCLUDE_CRYPTO_FLAG = -I./include/crypto
INCLUDE_FLAG = -I./include

# Directories
GMPUTILS_DIR = lib/gmpUtils
RSA_DIR = crypto/rsa
SRC_DIR = src

# src files
SRC_SOURCES = main.c
_SRC = $(SRC_SOURCES:.c=.o)
SRC = $(patsubst %,$(SRC_DIR)/%,$(_SRC))

# rsa files
RSA_SOURCES = rsa_keyGen.c rsa_encryption.c
_RSA = $(RSA_SOURCES:.c=.o)
RSA = $(patsubst %,$(RSA_DIR)/%,$(_RSA))

# gmpUtils files
GMPUTILS_SOURCES = gmpUtils_eulerTotient.c gmpUtils_coprimeNumber.c gmpUtils_getRandomPrime.c
_GMPUTILS = $(GMPUTILS_SOURCES:.c=.o)
GMPUTILS = $(patsubst %,$(GMPUTILS_DIR)/%,$(_GMPUTILS))


all: $(SRC_DIR)/$(EXEC) clean

$(SRC_DIR)/$(EXEC): $(SRC) $(RSA) $(GMPUTILS)
	$(CC) $(INCLUDE_CRYPTO_FLAG) $(INCLUDE_FLAG) -o $(EXEC) $(SRC) $(RSA) $(GMPUTILS) $(CFLAGS)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(INCLUDE_CRYPTO_FLAG) $(INCLUDE_FLAG) -o $@ -c $< $(CFLAGS) 

# Compile rsa files
$(RSA_DIR)/%.o: $(RSA_DIR)/%.c
	$(CC) $(INCLUDE_CRYPTO_FLAG) $(INCLUDE_FLAG) -o $@ -c $< $(CFLAGS)

# Compile gmpUtils files
$(GMPUTILS_DIR)/%.o: $(GMPUTILS_DIR)/%.c
	$(CC) $(INCLUDE_CRYPTO_FLAG) $(INCLUDE_FLAG) -o $@ -c $< $(CFLAGS)


clean:
	rm -rf $(SRC_DIR)/*.o $(RSA_DIR)/*.o $(GMPUTILS_DIR)/*.o
mrproper: clean
	rm -rf main
