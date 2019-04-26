#include <stdio.h>
#include <string.h>
#include <strings.h>

int rotationalEncrypt(char message[], int key);

int main(){
    char message[1000];
    int key, select;
    printf("Please select a number from the menu below:\n-------------------------------------\n");
    printf("1) Rotational Encryption\n");
    printf("2) Rotational Decryption\n");
    printf("3) Substitutional Encryption\n");
    printf("4) Substitutional Decryption\n");
    printf("To exit press 0\n-------------------------------------\n");
    scanf("%d", &select);
    //printf("%d\n", select);
    scanf("%d", &key);
    scanf("%s",message);
    printf("The message is: %s\n", message);
    printf("Key = %d\n-------------------------------------\n", key);
        switch(select){
        case 1: printf("You have chosen to perform Rotational Encryption for message = '%s' using key '%d'\n", message, key);
                rotationalEncrypt(message, key);
                printf("-------------------------------------\n");
                break;
        case 2: printf("Choice is 2\n");
                break;
        case 0: printf("Goodbye...");
                return 0;
        default: printf("Good luck\n");
                break;
    return 0;
    }
}
  
int rotationalEncrypt(char message[], int key){
        char ch;
        int cout;
        for(cout = 0; message[cout] != '0';++cout){
            ch = message[cout];
            
            if(ch >= 'a' && ch <= 'z'){
                ch = ch + key;
                
                if (ch > 'z'){
                    ch = ch - 'z' + 'a' - key;
                }
                message[cout] = ch;
            }
            else if (ch >= 'A' && ch <= 'Z'){
                ch = ch + key;
            
                if (ch > 'Z'){
                ch = ch - 'Z' + 'A' - key; 
            }

                message[cout] = ch;
            }
    }
    printf("Encrypted Message: %s\n", message);
    return 0;
}

int rotationalDecrypt(char message[], int key){
        char ch;
        int cout;
    	for(cout = 0; message[cout] != '\0'; ++cout){
		ch = message[cout];
		
		if(ch >= 'a' && ch <= 'z'){
			ch = ch - key;
			
			if(ch < 'a'){
				ch = ch + 'z' - 'a' + 1;
			}
			
			message[cout] = ch;
		}
		else if(ch >= 'A' && ch <= 'Z'){
			ch = ch - key;
			
			if(ch < 'A'){
				ch = ch + 'Z' - 'A' + 1;
			}
			
			message[cout] = ch;
		}
	}
	
	printf("Decrypted message: %s", message);
	
	return 0;
}
