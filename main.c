#include <stdio.h>
#include <string.h>
#include <strings.h>

int main(){
    char message[] = "attack", ch;
    int key = 1, cout = 0;
    printf("Welcome to the C encryptor/decryptor\n-------------------------------------\n");
    printf("Message: %s\n", message);
    printf("Rotational Shift = %d\n", key);
    
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
