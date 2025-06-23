#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void getOrder(char *key, int order[]) {
    int len = strlen(key);
    for (int i = 0; i < len; i++) {
        order[i] = i;
    }

    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (key[order[i]] > key[order[j]]) {
                int temp = order[i];
                order[i] = order[j];
                order[j] = temp;
            }
        }
    }
}

int main() {
    char plaintext[100], key[20], ciphertext[200];
    int order[20];
    
    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0';  

    printf("Enter the key (e.g., ZEBRAS): ");
    scanf("%s", key);

    int ptLen = strlen(plaintext);
    int keyLen = strlen(key);

    char cleanText[100];
    int k = 0;
    for (int i = 0; i < ptLen; i++) {
        if (isalpha(plaintext[i])) {
            cleanText[k++] = toupper(plaintext[i]);
        }
    }
    cleanText[k] = '\0';
    ptLen = strlen(cleanText);

    while (ptLen % keyLen != 0) {
        cleanText[ptLen++] = 'X';
        cleanText[ptLen] = '\0';
    }

    int rows = ptLen / keyLen;
    char matrix[rows][keyLen];

    k = 0;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < keyLen; j++)
            matrix[i][j] = cleanText[k++];

    getOrder(key, order);

    k = 0;
    for (int i = 0; i < keyLen; i++) {
        int col = order[i];
        for (int j = 0; j < rows; j++) {
            ciphertext[k++] = matrix[j][col];
        }
    }

    ciphertext[k] = '\0';

    printf("Columnar Cipher Text: %s\n", ciphertext);

    return 0;
}
