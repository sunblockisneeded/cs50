#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main (void)
{
    char *s = get_string("text: ");
    int len = strlen(s);
    char *t = malloc(len+1);

    strcpy(t,s);

    t[0] = toupper(t[0]);

    printf("s: %s\n",s);
    printf("t: %s\n",t);
}
