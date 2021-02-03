#include <stdio.h>
#include <cs50.h>
#include <math.h>

float get_money(void);
void change(int coin, int cents, int *total,  int *counter);

int main(void)
{
    int cents = round(get_money() * 100);
    int total = 0;
    int c = 0;

    change(25, cents, &total, &c);
    change(10, cents, &total, &c);
    change(5, cents, &total, &c);
    change(1, cents, &total, &c);

    printf("%i\n", c);
}

void change(int coin, int cents, int *total,  int *counter)
{
    int i = 0;
    while(*total < cents - coin + 1)
    {
        *total += coin;
        *counter = *counter + 1;
    }
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