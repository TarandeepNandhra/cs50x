#include <stdio.h>
#include <cs50.h>

int get_height(void);
void hash(int i);
void dot(int z);

int main(void)
{
    int a = get_height();
    for(int m=1; m<a+1; m++)
    {
        dot(a-m);
        hash(m);
        printf("  ");
        hash(m);
        printf("\n");
    }
}

int get_height(void)
{
    int p;
    do
    {
        p=get_int("Height: ");
    }
    while(p<1 || p>8);
    return p;
}

void hash(int i)
{
    for(int j=0; j<i; j++)
    {
        printf("#");
    }
}

void dot(int z)
{
    for(int x=0; x<z; x++)
    {
        printf(" ");
    }
}