#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main (void)
{
    string n = get_string("what's your answer: ");
    for(int i = 0 ; n[i] != '\0'; i++)
    {
        printf("%c",n[i]);
    }printf("\n");
}
