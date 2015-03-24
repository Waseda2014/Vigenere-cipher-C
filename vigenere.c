#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main (int argc, string argv[])
{  
    //goes through each index in argv[1] to check 
    //if everything is alpha
    int testval = 0; 
    string key = argv[1];
    if (argc == 2)
        for(int i = 0, n=strlen(key); i < n; i++)
        {
            if(isalpha(key[i]))
            {
              testval+=0;
        }     
        else
        {
            testval+=1;
        }               
    }      
    
    if (argc != 2 || testval!=0 )
    {
        printf("Usage: ./vigenere <key>\n");
        return 1;
    } 
    else 
    {    
        int k = 0; 
        int key_len = 0;  
        for(int i = 0, n=strlen(key); i < n; i++)
        {     
            key_len += 1;  
        }  
        //printf("The length of the key is:%i\n",key_len);
        //printf("%i \n",k);                         
        //prompts the user for the messge
        //printf("What is the message? ");    
        string s = GetString();                                  
        for (int i = 0, n=strlen(s); i < n; i++)
        { 
            if (isupper(key[i%key_len]))
            {
                k = (key[i%key_len]-65);
            }
            else if (islower(key[i%key_len]))
            {
                k = (key[i%key_len]-97);
            }                                         

            if (isalpha(s[i]))           
            {
                if(isupper(s[i]))
                {
                    printf("%c", (s[i]-65+k)%26+65);
                }
                else if(islower(s[i])) 
                {
                    printf("%c", (s[i]-97+k)%26+97);
                }
            }
            
            else
            {
                printf("%C", s[i]);
            }                       
        }                 
        printf("\n");     
        return 0;    
    }
}


