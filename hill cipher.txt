#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 3  

int charToIndex(char c) {
    return toupper(c) - 'A';
}

char indexToChar(int i) {
    return (i % 26) + 'A';
}

void encryptBlock(char block[3], int key[3][3], char cipher[3]) {
    int pt[3];
    for (int i = 0; i < 3; i++)
        pt[i] = charToIndex(block[i]);

    for (int i = 0; i < 3; i++) {
        int val = 0;
        for (int j = 0; j < 3; j++) {
            val += key[i][j] * pt[j];
        }
        cipher[i] = indexToChar(val % 26);
    }
}

int main() {
    char plaintext[100], ciphertext[100];
    int key[3][3];
    int i, j, len;

    printf("Enter 3x3 Key Matrix (9 integers):\n");
    for (i = 0; i < SIZE; i++)
        for (j = 0; j < SIZE; j++)
            scanf("%d", &key[i][j]);

    getchar(); 
    printf("Enter the plaintext (only letters): ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0';

    int k = 0;
    for (i = 0; plaintext[i] != '\0'; i++) {
        if (isalpha(plaintext[i])) {
            plaintext[k++] = toupper(plaintext[i]);
        }
    }
    plaintext[k] = '\0';
    len = strlen(plaintext);

    while (len % 3 != 0) {
        plaintext[len++] = 'X';
        plaintext[len] = '\0';
    }

    k = 0;
    for (i = 0; i < len; i += 3) {
        char block[3], cipher[3];
        block[0] = plaintext[i];
        block[1] = plaintext[i + 1];
        block[2] = plaintext[i + 2];

        encryptBlock(block, key, cipher);
        ciphertext[k++] = cipher[0];
        ciphertext[k++] = cipher[1];
        ciphertext[k++] = cipher[2];
    }

    ciphertext[k] = '\0';

    printf("Hill Cipher Text: %s\n", ciphertext);

    return 0;
}
