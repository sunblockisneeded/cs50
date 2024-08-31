#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int num [6] = { 4, 8, 5, 16, 23, 42};

    for(int i =0; i < 6; i++)
    {
        if (num [i] == 50)
        {
            printf("num %i is 50!\n",i);
        }
    }
    printf("Not found\n");
}
