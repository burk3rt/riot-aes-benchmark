#include <stdio.h>
#include "od.h"
#include "crypto/aes.h"
#include "aes-ecb.h"
#include "generator/generator.h"

#define KEY_SIZE AES_KEY_SIZE_128

void executeAesEcb(char* message, int currentRound, FILE* filePointer) {
    cipher_t cipher;
    int dataLength = strlen(message);
    uint8_t* input = malloc(dataLength);
    memmove(input, message, dataLength);
    int requiredBlocks = dataLength / AES_BLOCK_SIZE;
    if(dataLength % AES_BLOCK_SIZE) {
        requiredBlocks++;
    }
    uint8_t* output = calloc(requiredBlocks, AES_BLOCK_SIZE);
    uint8_t* key = malloc(KEY_SIZE);
    random_bytes(key, KEY_SIZE);
    printf("Key\n");
    od_hex_dump(key, KEY_SIZE, 0);
    sprintf((char *)input, "%s", message);
    cipher_init(&cipher, CIPHER_AES, key, KEY_SIZE);
    uint32_t _benchmark_time_encryption = xtimer_now_usec();
    cipher_encrypt(&cipher, input, output);
    _benchmark_time_encryption = (xtimer_now_usec() - _benchmark_time_encryption);
    printf("Plaintext: \t");
    od_hex_dump(input, AES_BLOCK_SIZE, 0);
    printf("Ciphertext: \t");
    od_hex_dump(output, AES_BLOCK_SIZE, 0);
    printf("Decrypted text: \t");
    uint32_t _benchmark_time_decryption = xtimer_now_usec();
    cipher_decrypt(&cipher, output, input);
    _benchmark_time_decryption = (xtimer_now_usec() - _benchmark_time_decryption);
    od_hex_dump(input, AES_BLOCK_SIZE, 0);
    uint32_t benchmarkResults[2];
    benchmarkResults[0] = _benchmark_time_encryption;
    benchmarkResults[1] = _benchmark_time_decryption;
    benchmark_save_runtime(benchmarkResults, currentRound, filePointer);
    free(input);
    free(output);
    free(key);
}
