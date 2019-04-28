//Name: Jacob Tye
//Student Number: c3304972
//Course Code: ENGG1003
//Description: Programming Assignment 1 for Intro to Procedural Programming
//             When using the program I have had to hard code variables as my inputt file attempt was unsuccessful
//             Please feel free to test away but enter the new values where the comments turn capital 


#include <stdio.h>
#include <string.h>
#include <strings.h>

int rotationalEncrypt(char message[], int key);         //Function prototypes for rotational encrypt and decrypt
int rotationalDecrypt(char message[], int key);

int main(){
    char message[] = "Message here";                    //Hard coded message variable PLEASE ENTER MESSAGE HERE WHEN TESTING
    int key = 1, select = 2;                            //Hard coded key and selection variable PLEASE ENTER KEY AND SELECTION (EITHER 1 OR 2) HERE WHEN TESTING
    printf("Please select a number from the menu below:\n-------------------------------------\n");         //Menu attempt (from when I was trying to implement an input file)
    printf("1) Rotational Encryption\n");
    printf("2) Rotational Decryption\n");
    printf("To exit press 0\n-------------------------------------\n");
    //scanf("%d\n", &select);                         //Scanning variables to parse (From attempt of file input)
    //printf("%d\n", select);
    //scanf("%d\n", &key);
    printf("Message = %s\n",message);                   //Printing variables to be parsed through chosen function
    printf("Key = %d\n-------------------------------------\n", key);
    //scanf("%[^\n]s",message);
        switch(select){                                 //Switch statement to select between functions, a complete program would have had substitutional cases as well
        case 1: printf("You have chosen to perform Rotational Encryption for message = '%s' using key '%d'\n", message, key);
                rotationalEncrypt(message, key);
                printf("-------------------------------------\n");
                break;
        case 2: printf("You have chosen to perform Rotational Decryption for message = '%s' using key '%d'\n", message, key);
                rotationalDecrypt(message, key);
                printf("-------------------------------------\n");
        case 0: printf("Goodbye...");
                return 0;
        default: printf("Good luck\n");
                break;
    return 0;                                           //End of main 
    }
}
  
int rotationalEncrypt(char message[], int key){         //Rotational Encryption function 
        char ch;                                        //Declaring required variable to successfully complete loops
        int cout;
        for(cout = 0; message[cout] != '0';++cout){     //for loop using cout (counter) to represent each character in a string, cout is increased by an increment of one after each iteration
            ch = message[cout];                         //ch represents the actual letter assigned to cout's current position
            
            if(ch >= 'a' && ch <= 'z'){                 //if the current letter is a lowercase letter in the alphabet add the key's value and that is the new letter
                ch = ch + key;
                
                if (ch > 'z'){                          //if the new value is greater than z bring it back to the begininng of the alphabet and reassign
                    ch = ch - 'z' + 'a' - key;
                }
                message[cout] = ch;                     //building new message as the loop goes
            }
            else if (ch >= 'A' && ch <= 'Z'){           //exact same if loop as before just for capitals
                ch = ch + key;
            
                if (ch > 'Z'){
                ch = ch - 'Z' + 'A' - key; 
            }
                message[cout] = ch;                     //building the message as the loop goes
            }
    }
    printf("Encrypted Message: %s\n", message);         //printing the message
    return 0;                                           //end of program, would have liked to be able to give user the ability to make a second selection but ran out of time
}

int rotationalDecrypt(char message[], int key){         //Rotationa Encryption function
        char ch;                                        //Declaring required variables
        int cout;
    	for(cout = 0; message[cout] != '0'; ++cout){    //same for loop as rotational encrypt
		ch = message[cout];
		
		if(ch >= 'a' && ch <= 'z'){                     //only difference is that decryption is in reverse ie: shifting the letters backwards in the alphabet
			ch = ch - key;
			
			if(ch < 'a'){                               //hence why we no0w check for less than a rather than greater than z
				ch = ch + 'z' - 'a' + 1;
			}			
			message[cout] = ch;                         //building new message as the loop goes
		}
		else if(ch >= 'A' && ch <= 'Z'){                //same loop for upper case 
			ch = ch - key;
			
			if(ch < 'A'){
				ch = ch + 'Z' - 'A' + 1;
			}			
			message[cout] = ch;                         //building new message as the loop goes 
		}
	}	
	printf("Decrypted message: %s\n", message);	        //printing new message     
	return 0;                                           //end of program
}
