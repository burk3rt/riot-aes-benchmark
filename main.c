#include "aes-ecb.h"
#include <stdio.h>
#include <stdint.h>
#include "generator/generator.h"
#include "time.h"


#define ROUNDS 100
#define MESSAGE_LENGTH 100

int main(void)
{
    printf("Number of rounds: %d\n", ROUNDS);
    FILE* filePointer = createBenchmarkFile("aes-ecb-128");
    for(int round = 1; round <= ROUNDS; round++){
        char* message = (char*)malloc(MESSAGE_LENGTH * sizeof(char) + 1);
        generateMessage(message, MESSAGE_LENGTH);
        printf("Round %d of %d\nMessage to encrypt/decrypt: %s\n", round, ROUNDS, message);
        executeAesEcb(message, round, filePointer);
        free(message);
    }
    printf("Benchmark done!\nClosing file access ...\n");
    fclose(filePointer);
    return 0;
}
