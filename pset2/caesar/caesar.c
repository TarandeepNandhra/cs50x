#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if(argv[1] == 0)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    float a =  atof(argv[1]);
    int b = a;
    if (argc == 2 && a >= 1 && a == b)
    {
        //printf("Success %s\n", argv[1]);
        //valid key continue to get plaintext
        
        string s = get_string("plaintext: ");

        //converting key mod 26
        int rawkey = atoi(argv[1]);
        int key = rawkey%26;
        
        printf("ciphertext:");
        
        for (int i = 0, n = strlen(s); i < n; i++)
        {
            if (s[i] >= 'a' && s[i] <= 'z')
            {
                if (s[i] + key > 122)
                {
                    printf("%c", s[i] + key - 26 );
                }
                else
                {
                    printf("%c", s[i] + key);
                }
            }
            else
            {
                if (s[i] >= 'A' && s[i] <= 'Z')
            {
                    if (s[i] + key > 90)
                    {
                        printf("%c", s[i] + key - 26 );
                    }
                    else
                    {
                        printf("%c", s[i] + key );
                    }
            }
            else
            {
                 printf("%c", s[i]);   
            }
            
            }
            
        }
        printf("\n");
        return 0;
    }    
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

}