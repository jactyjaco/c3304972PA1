#include <stdio.h>
#include <string.h>
#include <strings.h>

int rotationalEncrypt(char message[], int key);

int main(){
    char message[1000];
    int key = 1;
    printf("Please select a number from the menu below:\n-------------------------------------\n");
    printf("1) Rotational Encryption\n");
    printf("2) Rotational Decryption\n");
    printf("3) Substitutional Encryption\n");
    printf("4) Substitutional Decryption\n");
    printf("To exit press 0\n-------------------------------------\n");
    fgets(message,1000,stdin);
    printf("Your message: %s\n", message);
    printf("Rotational Shift = %d\n-------------------------------------\n", key);
    rotationalEncrypt(message, key);
    return 0;
}

int rotationalEncrypt(char message[], int key){
        char ch;
        int cout;
        for(cout = 0; message[cout] != '0';++cout){
            ch = message[cout];
            
            if(ch >= 'a' && ch <= 'z'){
                ch = ch + key;
                
                if (ch > 'z'){
                    ch = ch - 'z' + 'a' - 1;
                }
                message[cout] = ch;
            }
            else if (ch >= 'A' && ch <= 'Z'){
                ch = ch + key;
            
                if (ch > 'Z'){
                ch = ch - 'Z' + 'A' - 1; 
            }

                message[cout] = ch;
            }
    }
    printf("Encrypted Message: %s\n", message);
    return 0;
}
