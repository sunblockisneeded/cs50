#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    char *s = get_string("s: ");
    char *t = get_string("t: ");

    if (strlen(s) != strlen(t))
    {
        printf("different\n");
        return 1;
    }
    for (int i = 0 ; i< strlen(s); i++)
    {
        if( s[i] != t[i])
        {
        printf("differet\n");
        return 1;
        }
    }
    printf("same\n");
    return 0;
}
