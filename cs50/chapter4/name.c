#include <stdio.h>
#include <cs50.h>
#include <string.h>
int main(void)
{
    string names[4] = {"EMMA", "RODRIGO", "BRAIN", "DAVID"};
    for (int i =0 ; i < 4 ; i++)
    {
        if (strcmp(names[i],"EMMA") == 0 )
        {
            printf("found\n");
            return 0;
        }
        printf("Not found\n");
        return 1;
    }
}
