#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "crypto/ciphers.h"
#include "crypto/aes.h"

cipher_t cipher;
int err;
uint8_t input[AES_BLOCK_SIZE] = {0};
uint8_t output[AES_BLOCK_SIZE] = {0};
sprintf((char*)input, "Testnachricht");

uint8_t provideKey(){
    uint8_t key[AES_KEY_SIZE] = {
        0x64, 0x52, 0x67, 0x55,
        0x6B, 0x58, 0x70, 0x32,
        0x73, 0x35, 0x75, 0x38,
        0x78, 0x2F, 0x41, 0x3F
    };
    return key;
}

int initializeCipherStruct(uint8_t key){
    if (err = cipher_init(&cipher, CIPHER_AES_128, key, AES_KEY_SIZE)) != CIPHER_INIT_SUCCESS) {
        printf("Failed to initialize cipher structure %d\n", err);
        exit(err);
    }
}

int encryptMessage() {
    if (err = cipher_encrypt(&cipher, input, output)) != 1) {
        printf("Failed to encrypt data: &d\n", err);
        exit(err);
    }
}

uint8_t returnInput() {
    return input;
}

uint8_t returnOutput() {
    return output;
}