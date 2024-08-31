#include <stdio.h>
#include <cs50.h>

int main (void)
{
    int n = get_int("n: ");
    int sum = 0 ;
    for (int i = 1 ; i <= n ; i++)
    {
        sum = sum + i;
    }
    printf("add 1 to %i is %i\n",n,sum);
}
