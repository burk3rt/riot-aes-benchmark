#include <stdio.h>
#include "od.h"
#include "crypto/aes.h"

void executeAesEcb(char * message) {
    cipher_t cipher;
    uint8_t input[AES_BLOCK_SIZE] = {0};
    uint8_t output[AES_BLOCK_SIZE] = {0};
    uint8_t key[] = {
        0x64, 0x52, 0x67, 0x55,
        0x6B, 0x58, 0x70, 0x32,
        0x73, 0x35, 0x75, 0x38,
        0x78, 0x2F, 0x41, 0x3F
    };
    sprintf((char *)input, "%s", message);
    cipher_init(&cipher, CIPHER_AES_128, key, AES_KEY_SIZE_128);
    cipher_encrypt(&cipher, input, output);
    printf("Plaintext: \t");
    od_hex_dump(input, AES_BLOCK_SIZE, 0);
    printf("Ciphertext: \t");
    od_hex_dump(output, AES_BLOCK_SIZE, 0);
    printf("Decrypted text: \t");
    cipher_decrypt(&cipher, output, input);
    od_hex_dump(input, AES_BLOCK_SIZE, 0);
}
