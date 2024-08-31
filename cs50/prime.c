#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>

int prime (int i);

int main (void)
{
    int min = get_int("Minimum: ");
    int max = get_int("Maximum: ");

    for (int i = min ; i <= max ; i++)
    {
        int k = prime(i);
        if(k != 0)
        {
            printf("%i\n",k);
        }
    }
}

int prime (int i)
{
    int counter = 0;
    for (int j = 1; j <= i; j++)
    {
        if (i % j == 0)
        counter ++;
    }
    if(counter ==2)
    {
        return i;
    }
    else
    return 0;
}

