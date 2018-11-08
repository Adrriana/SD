#include<stdio.h>
#include<string.h>
void find_frequency(char [], int []);
int main(){
    char text[] = "AZI E O ZI MINUNATA";
    char key[] = "HELLO";
    int textLen = strlen(text), keyLen = strlen(key), i, j;

    char newKey[textLen], encrypted[textLen], decrypted[textLen];


    //generating new key
    for(i = 0, j = 0; i < textLen; ++i, ++j){
        if(j == keyLen)
            j = 0;

        newKey[i] = key[j];
    }

    newKey[i] = '\0';

    //encryption
    for(i = 0; i < textLen; ++i)
        encrypted[i] = ((text[i] + newKey[i]) % 26) + 'A';

    encrypted[i] = '\0';

    //decryption
    for(i = 0; i < textLen; ++i)
        decrypted[i] = (((encrypted[i] - newKey[i]) + 26) % 26) + 'A';

    decrypted[i] = '\0';

    printf("Textul este: %s", text);
    printf("\nKey: %s", key);
    printf("\nNoua cheie generata: %s", newKey);
    printf("\nMesajul criptat: %s", encrypted);
    printf("\nMesajul decriptat: %s", decrypted);


   int c, count[26] = {0};

   printf("\nInput a string\n");
   gets(encrypted);

   find_frequency(encrypted, count);

   printf("Character Count\n");

   for (c = 0 ; c < 26 ; c++)
      printf("%c \t  %d\n", c + 'a', count[c]);
      return 0;
}



void find_frequency(char s[], int count[]) {
   int c = 0;

   while (s[c] != '\0') {
      if (s[c] >= 'a' && s[c] <= 'z' )
         count[s[c]-'a']++;
      c++;
   }
}
