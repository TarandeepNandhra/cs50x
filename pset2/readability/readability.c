#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void)
{
    string s = get_string("Text: ");
    int letters = 0;

    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            letters++;
        }

        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            letters++;
        }
        else
        {

        }
    }

    printf("%i letter(s)\n", letters);

    int words = 1;
    for (int i = 0, n = strlen(s); i < n; i++)
    {
       if (s[i] == ' ')
       {
           words++;
       }
       else
       {

       }
    }

    printf("%i word(s)\n", words);

    int sentences = 0;
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (s[i] == '.' || s[i] == '!' || s[i] == '?')
        {
            sentences++;
        }
    }
    printf("%i sentence(s)\n", sentences);

    float S = ( (float) sentences / (float) words)*100;
    float L = ( (float) letters / (float) words)*100;

    float index = (0.0588 * L) - (0.296 * S) - 15.8;

    if (index<1)
    {
        printf("Before Grade 1\n");
    }

    else
    {
        if (index<16)
        {
            printf("Grade %.0f\n", round(index));
        }
        else
        {
            printf("Grade 16+\n");
        }
    }
}

