#include "algorithms/aes-ecb.h"
#include "algorithms/aes-cbc.h"
#include <stdio.h>
#include <stdint.h>
#include "time.h"
#include "string.h"


#define ROUNDS 1000
<<<<<<< HEAD
#define MESSAGE_LENGTH 512 // in BYTES
=======
#define MESSAGE_LENGTH 128// in BYTES
>>>>>>> c59134f44d584814644d95fcbe058ce185350297
#define KEY_SIZE 16 // in BYTES
#define ECB_MODE 1 // 0=OFF, 1=ON

int main(void)
{
    printf("Starting Benchmark ...\nNUMBER OF ROUNDS: %d\nWORDLENGTH: %d BYTES\n", ROUNDS, MESSAGE_LENGTH);
    if(ECB_MODE){
        printf("Mode: ELECTRONIC CODEBOOK\n");
        executeAesEcb(ROUNDS, KEY_SIZE, MESSAGE_LENGTH);
    } else {
        printf("Mode: CIPHER BLOCKER CHAINING");
        executeAesCbc(ROUNDS, KEY_SIZE, MESSAGE_LENGTH);
    }
    printf("Benchmark done!\n");
    return 0;
}
