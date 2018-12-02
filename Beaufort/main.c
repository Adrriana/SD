#include<stdlib.h>
#include<stdio.h>
#define NR 64

char Encrypt(char *alphabet, int *pKey, char text, int pos)
{
    int encrText;
    int i;
    for ( i = 0; i < 26; i++)
    {
        if (text == alphabet[i])
        {
            encrText = (i + pKey[pos]) % 26;
            return alphabet[encrText];
        }
    }
}

char Decrypt(char *alphabet, int *pKey, char text, int pos)
{
    int decrText;
    int i;
    for (i = 0; i < 26; i++)
    {
        if (text == alphabet[i])
        {
            decrText = (i - pKey[pos]) % 26;
            return alphabet[decrText];
        }
    }
}

int main() {
    char plainText[NR], alphabet[27] = "abcdefghijklmnopqrstuvwxyz", key[NR], encrText[NR], decrText[NR];
    int pKey[NR], pos = 0;
    printf("plaintext:\n");
    gets(plainText);
    printf("key\n");
    gets(key);

    int textLength = strlen(plainText);
    int keyLength = strlen(key);
    int i,j;
    for (i = 0; i < keyLength; i++) {
        for(j = 0; j < 26; j++)
        {
            if (key[j] == alphabet[i])
            {
                pKey[j] = i;
            }
        }
    }

    int x = 1;

    printf("\nChoose:\n1.Encrypt text.\n2.Decrypt text.\n");
    scanf("%d", &x);

    switch (x)
    {
        case 1:
            for( i = 0; i < textLength; i++)
            {
                encrText[i] = Encrypt(alphabet, pKey, plainText[i], pos % keyLength);
                ++pos;
            }
            encrText[textLength] = '\0';
            printf("\nEncrypted text: %s\n", encrText);
            break;

        case 2:
            for( i = 0; i < textLength; i++)
            {
                decrText[i] = Decrypt(alphabet, pKey, plainText[i], pos % keyLength);
                ++pos;
            }
            decrText[textLength] = '\0';
            printf("\nDecrypted text: %s\n", decrText);
            break;

        default:
            printf("Exit");
    }

    return 0;
}
