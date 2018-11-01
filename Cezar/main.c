#include <stdio.h>
#include <string.h>
char *criptare(char[]);
void *decriptarea(char[]);
void main()
{
    int i, key, choice, flag=0;
    char mesaj[255];
    char *c_text;

char *criptare(char text[]){
    int key,i;

    printf("introduceti cheia pentru criptare:");
    scanf("%d",&key);
    for(i=0;i<strlen(text);i++){
        if(text[i]>='a' && text[i]<='z'){
            text[i] = text[i]+key;
            if(text[i]>'z'){
                text[i]=text[i]-26;
            }
        }
    }
    printf("mesajul criptat este: %s",text);
    return text;
}
void *decriptarea(char text[]){
     int i,key;
     char cipher[255];
     strcpy(cipher,text);
     printf("\n Decryption Process \n");
     for(key=1;key<=26;key++){
        for(i=0;i<strlen(text);i++){
            if(text[i]>='a' && text[i]<='z'){
                cipher[i] = text[i]-key;
                if(cipher[i]<'a'){
                    cipher[i]=cipher[i]+26;
                }
            }
        }
        printf("\n textul decriptat %s",cipher);
     }
}
    printf("Introduceti textul:");
    scanf("%[^\n]",mesaj);
   do{
        printf("\n apasati 1 pentru criptare \n apasati 2 pentru decriptare \n apasati 0 pentru a iesi \n");
        scanf("%d",&choice);
        switch(choice){
        case 1:
            c_text=criptare(mesaj);
            flag=1;
            break;
        case 2:
            if(flag==1)
                decriptarea(c_text);
                else
                    printf("efectuati mai intai procesul de criptare");
                break;
        case 0:
            break;
        default:
            printf("\n introduceti o alegere valida\n");
            break;
            }
    }while(choice!=0);
}
