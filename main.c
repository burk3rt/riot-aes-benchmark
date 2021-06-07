#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "crypto/aes.h"
#include "crypto/ciphers.h"
#include "RIOT/sys/include/od.h"

int main(void)
{
    cipher_t cipher;
    uint8_t input[AES_BLOCK_SIZE] = {0};
    uint8_t output[AES_BLOCK_SIZE] = {0};
    sprintf((char *)input, "Testnachricht");

    puts("Board initialized!");
    uint8_t key[] = {
        0x64, 0x52, 0x67, 0x55,
        0x6B, 0x58, 0x70, 0x32,
        0x73, 0x35, 0x75, 0x38,
        0x78, 0x2F, 0x41, 0x3F
    };
    cipher_init(&cipher, CIPHER_AES_128, key, AES_KEY_SIZE);
    cipher_encrypt(&cipher, input, output);
    printf("Klartext: \t");
    od_hex_dump(input, AES_BLOCK_SIZE, 0);
    printf("Ciphertext: \t");
    od_hex_dump(output, AES_BLOCK_SIZE, 0);
    printf("Decypher: \t");
    od_hex_dump(input, AES_BLOCK_SIZE, 0);
    return 0;
}
