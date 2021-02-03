#include <stdio.h>
#include <cs50.h>
#include <math.h>

float get_money(void);


int main(void)
{
    double cents = round(get_money()* 100);

    double b = cents/25;
    int w = b;
    cents = cents - w*25;
    int c = w;
   
    b = cents/10;
    w=b;
    cents = cents - w*10;
    c = c+w;
    
    b = cents/5;
    w=b;
    cents = cents - w*5;
    c = c+w;
    
    b = cents;
    w=b;
    cents = cents - w;
    c = c+w;
    
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

