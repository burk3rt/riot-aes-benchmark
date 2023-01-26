#include "algorithms/aes-ecb.h"
#include "algorithms/aes-cbc.h"
#include "algorithms/aes-ctr.h"
#include <stdio.h>
#include <stdint.h>
#include "time.h"
#include "string.h"
#include "shell.h"


#define ROUNDS 1000
#define MESSAGE_LENGTH 2048 // in BYTES
#define KEY_SIZE 24 // in BYTES

int ecb_command_handler(int argc, char** argv) {
    (void)argc;
    (void)argv;
    printf("Mode: ELECTRONIC CODEBOOK\n");
    executeAesEcb(ROUNDS, KEY_SIZE, MESSAGE_LENGTH);
    printf("Benchmark done!\n");
    return 0;
}

int cbc_command_handler(int argc, char** argv) {
    (void)argc;
    (void)argv;
    printf("Mode: CIPHER BLOCKER CHAINING\n");
    executeAesCbc(ROUNDS, KEY_SIZE, MESSAGE_LENGTH);
    printf("Benchmark done!\n");
    return 0;
}

int ctr_command_handler(int argc, char** argv) {
    (void)argc;
    (void)argv;
    printf("Mode: COUNTER MODE\n");
    executeAesCtr(ROUNDS, KEY_SIZE, MESSAGE_LENGTH);
    printf("Benchmark done!\n");
    return 0;
}

int main(void)
{
     shell_command_t commands[] = {
        { "ecb", "AES ECB Mode Benchmark", ecb_command_handler },
        { "cbc", "AES CBC Mode Benchmark", cbc_command_handler },
        { "ctr", "AES CTR Mode Benchmark", ctr_command_handler },
        { NULL, NULL, NULL }
    };

    char line_buf[SHELL_DEFAULT_BUFSIZE];
    shell_run(commands, line_buf, SHELL_DEFAULT_BUFSIZE);
    printf("Benchmark ready\nNUMBER OF ROUNDS: %d\nWORDLENGTH: %d BYTES\n", ROUNDS, MESSAGE_LENGTH);
    printf("Benchmark done!\n");
    return 0;
}
