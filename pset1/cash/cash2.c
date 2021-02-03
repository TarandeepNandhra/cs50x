#include <stdio.h>
#include <cs50.h>
#include <math.h>

float get_money(void);

int main(void)
{
    double cents = round(get_money()* 100);
    int i = 0;
    int c = 0;
    while(i<cents)
    {
        i=i+25;
        c++;
    }
    c=c-1;
    i=i-25;
    
    while(i<cents)
    {
        i=i+10;
        c++;
    }
    c=c-1;
    i=i-10;
    
    while(i<cents)
    {
        i=i+5;
        c++;
    }
    c=c-1;
    i=i-5; 
    
    while(i<cents)
    {
        i=i+1;
        c++;
    }
    printf("%i\n", c);
}


float get_money (void)
{
    float p;
    do
    {
        p = get_float("Change owed: ");
    }
    while (p<0);
    return p;
}