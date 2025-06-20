#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char plaintext[100];
    char ciphertext[100];
    
    char key[26] = {
        'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', 
        'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 'Z',
        'X', 'C', 'V', 'B', 'N', 'M'
    };

    printf("Enter plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    for (int i = 0; plaintext[i] != '\0'; i++) {
        char ch = plaintext[i];
        if (isalpha(ch)) {
            int index = tolower(ch) - 'a';
            char encrypted = key[index];

            ciphertext[i] = isupper(ch) ? encrypted : tolower(encrypted);
        } else {
            ciphertext[i] = ch;  
        }
    }

    ciphertext[strlen(plaintext)] = '\0'; 

    printf("Ciphertext: %s\n", ciphertext);

    return 0;
}
