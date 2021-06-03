#include <stdio.h>
#include "algorithms/aes-ecb.h"
#include "od.h"

int main(void)
{
    puts("Board initialized!");
    uint8_t key = provideKey();
    initializeCipherStruct(key);
    printf("Klartext: \t");
    od_hex_dump_ext(returnInput, AES_BLOCK_SIZE, 0, 0);
    printf("Ciphertext: \t");
    od_hex_dump_ext(returnOutput, AES_BLOCK_SIZE, 0, 0);
    return 0;
}
