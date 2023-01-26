#include <stdio.h>

#include "crypto/ciphers.h"
#include "crypto/aes.h"
#include "aes-ctr.h"

#include "od.h"


void executeAesCtr(int numberOfRounds, int keySize, size_t messageLength){
    printf(";Round;Encrypt(ms);Decrypt(ms)\n");
    for(int round = 1; round <= numberOfRounds; round++){
        uint8_t* input = malloc(messageLength);
        uint8_t* decryptBuffer = malloc(messageLength);
        uint8_t* nonce = malloc(keySize);
        random_bytes(input, messageLength);
        random_bytes(nonce, AES_BLOCK_SIZE);
        cipher_t cipher;
        int requiredBlocks = messageLength / AES_BLOCK_SIZE;
        if(messageLength % AES_BLOCK_SIZE) {
            requiredBlocks++;
        }
        size_t total_len = requiredBlocks * AES_BLOCK_SIZE;
        uint8_t* output = calloc(requiredBlocks, AES_BLOCK_SIZE);
        uint8_t* key = malloc(keySize);
        random_bytes(key, keySize);
        cipher_init(&cipher, CIPHER_AES, key, keySize);


        uint32_t _benchmark_time_encryption = xtimer_now_usec();
        cipher_encrypt_ctr(&cipher, nonce, 0, input, total_len, output);
        _benchmark_time_encryption = (xtimer_now_usec() - _benchmark_time_encryption);

        uint32_t _benchmark_time_decryption = xtimer_now_usec();
        cipher_decrypt_ctr(&cipher, nonce, 0, output, total_len, decryptBuffer);
        _benchmark_time_decryption = (xtimer_now_usec() - _benchmark_time_decryption);


        printf(";%d;%lu;%lu\n", round, _benchmark_time_encryption, _benchmark_time_decryption);
        free(input);
        free(output);
        free(key);
        free(decryptBuffer);
    }
}
