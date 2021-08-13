#ifndef AES_ECB_H
#define AES_ECB_H

#define AES_ECB_EXEC(MESSAGE, FUNCTION)

void executeAesEcb(char * message);


/*uint8_t setupAESInput(void);
uint8_t setupAESOutput(void);
uint8_t generateKey(void);
void initializeCipher(cipher_t *cipher, cipher_id_t cipher_id, const uint8_t *key, uint8_t key_size);
void encryptData(const cipher_t *cipher, const uint8_t *input, uint8_t *output);
void decryptData(const cipher_t *cipher, const uint8_t *input, uint8_t *output);*/

#endif
