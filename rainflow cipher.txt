#include <stdio.h>
#include <string.h>

void railFenceEncrypt(char *plaintext, int rails, char *ciphertext) {
    int len = strlen(plaintext);
    char rail[rails][len];

    for (int i = 0; i < rails; i++)
        for (int j = 0; j < len; j++)
            rail[i][j] = '\n';

    int row = 0, dir_down = 0;

    for (int i = 0; i < len; i++) {
        rail[row][i] = plaintext[i];
        if (row == 0 || row == rails - 1)
            dir_down = !dir_down;

        row += dir_down ? 1 : -1;
    }

    int k = 0;
    for (int i = 0; i < rails; i++)
        for (int j = 0; j < len; j++)
            if (rail[i][j] != '\n')
                ciphertext[k++] = rail[i][j];
    
    ciphertext[k] = '\0';
}

int main() {
    char plaintext[100], ciphertext[100];
    int rails;

    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0';  

    printf("Enter number of rails (e.g., 3): ");
    scanf("%d", &rails);

    railFenceEncrypt(plaintext, rails, ciphertext);

    printf("Rainfall Cipher Text (Rail Fence): %s\n", ciphertext);

    return 0;
}
