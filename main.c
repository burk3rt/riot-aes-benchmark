#include "aes-ecb.h"
#include <stdio.h>
#include <stdint.h>

int main(void)
{
    puts("In main!");
    executeAesEcb("Test");
    AES_ECB_EXEC("Test", executeAesEcb());
    return 0;
}
