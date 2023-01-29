#include "algorithms/aes-ecb.h"
#include "algorithms/aes-cbc.h"
#include "algorithms/aes-ctr.h"
#include <stdio.h>
#include <stdint.h>
#include "time.h"
#include "string.h"
#include "shell.h"


#define MESSAGE_LENGTH 2048 // in BYTES

void ecb_command_handler(uint16_t key_size, uint16_t rounds) {

    printf("Mode: ELECTRONIC CODEBOOK - %u Bit, # of rounds: %u\n", key_size*8, rounds);
    executeAesEcb(rounds, key_size, MESSAGE_LENGTH);
    printf("Benchmark done!\n");
}

void cbc_command_handler(uint16_t key_size, uint16_t rounds) {

    printf("Mode: CIPHER BLOCKER CHAINING - %u Bit, # of rounds: %u\n", key_size*8, rounds);
    executeAesCbc(rounds, key_size, MESSAGE_LENGTH);
    printf("Benchmark done!\n");
}

void ctr_command_handler(uint16_t key_size, uint16_t rounds) {

    printf("Mode: COUNTER MODE - %u Bit, # of rounds: %u\n", key_size*8, rounds);
    executeAesCtr(rounds, key_size, MESSAGE_LENGTH);
    printf("Benchmark done!\n");
}

void executeAll(uint16_t key_size, uint16_t rounds){
    if(key_size == 16){
        ecb_command_handler(key_size, rounds);
    }
    cbc_command_handler(key_size, rounds);
    ctr_command_handler(key_size, rounds);
}


int main(void)
{
    uint16_t rounds = 1000;
    uint16_t key_size = 16; // In bytes, this must be changed in Makefile

    executeAll(key_size, rounds);

    printf("All Benchmarks done!\n");
    return 0;
}
