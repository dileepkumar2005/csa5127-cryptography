#include <stdio.h>
#include <stdint.h>
#include <string.h>

void DES_encrypt(uint8_t *data, uint8_t *key) {
    for (int i = 0; i < 8; i++) {
        data[i] ^= key[i]; 
    }
}

void DES_decrypt(uint8_t *data, uint8_t *key) {
    for (int i = 0; i < 8; i++) {
        data[i] ^= key[i]; 
    }
}

void TripleDES_encrypt(uint8_t *plaintext, uint8_t *K1, uint8_t *K2, uint8_t *K3, uint8_t *ciphertext) {
    memcpy(ciphertext, plaintext, 8);

    DES_encrypt(ciphertext, K1);   
    DES_decrypt(ciphertext, K2);    
    DES_encrypt(ciphertext, K3);    
}

int main() {
    uint8_t plaintext[8] = "ABCDEFGH";  
    uint8_t K1[8] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08};
    uint8_t K2[8] = {0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x10};
    uint8_t K3[8] = {0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18};
    uint8_t ciphertext[8];

    printf("Plaintext: %s\n", plaintext);
    TripleDES_encrypt(plaintext, K1, K2, K3, ciphertext);

    printf("Ciphertext (hex): ");
    for (int i = 0; i < 8; i++) {
        printf("%02X ", ciphertext[i]);
    }
    printf("\n");

    return 0;
}
