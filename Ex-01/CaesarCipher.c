#include <stdio.h>
#include <string.h>
#include <ctype.h>
void decrypt(char text[], int key) {
    char ch;
    for (int i = 0; text[i] != '\0'; ++i) {
        ch = text[i];
        char c;
        if (isalnum(ch)) {
            if (islower(ch)) {
                c=(ch - 'a' - key);
                if(c<0){
                    ch=c+26+'a';
                }
                else{
                    ch = ( c% 26) + 'a';
                }
            }
            if (isupper(ch)) {
                c=(ch - 'A' - key);
                if(c<0){
                    ch=c+26+'A';
                }
                else{
                    ch = ( c% 26) + 'A';
                } 
            }
            if (isdigit(ch)) {
                c=(ch - '0' - key);
                if(c<0){
                    ch=c+10+'0';
                }
                else{
                    ch = ( c% 10) + '0';
                }
            } 
        }
        else {
            printf("Invalid Message");
        }
        text[i] = ch;
    }
    printf("Decrypted message: %s", text); 
}
void encrypt(char text[], int key) 
{
    char ch;
    for (int i = 0; text[i] != '\0'; ++i) 
    {
        ch = text[i];
        char c;
        if (isalnum(ch)) 
        {
            if (islower(ch)) {
                ch = ((ch - 'a' + key) % 26) + 'a';
            }
            if (isupper(ch)) {
                ch = ((ch - 'A' + key) % 26) + 'A'; 
            }
            if (isdigit(ch)) {
                ch = ((ch - '0' + key) % 10) + '0';
            } 
        }
        else {
            printf("Invalid Message");
        }
        text[i] = ch;
    }
    printf("Encrypted message: %s\n", text); 
    decrypt(text,key);
}

int main() {
    int key;
    char text[100],ch; 
    printf("Enter the msg : ");
    scanf("%s", text);
    printf("Enter the Key : ");
    scanf("%d", &key);
    encrypt(text,key);
}

