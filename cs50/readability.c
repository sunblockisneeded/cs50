#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int *p1;
int count_letters(string text);

int main(void)
{
    string a = get_string("Text: ");
    count_letters (a);
    printf("len : %i\n",count_letters (a));
    printf("pointer: %i\n",*p1);
}

int count_letters(string text)
    {
    int len = strlen(text);
    p1 = &len;
    char a[len];
    for (int i = 0 ; i <len ; i++ )
    {
        a[i] = (char)text[i];
    }
    int counter = 0;
    for(int i = 0 ; i< len ; i++)
    {
        if( isalnum(a[i]) == 0 || isspace(a[i]) ==0 )
        {
            if( ispunct(a[i]) == 0)
            {
            counter ++;
            }
        }
    }
    return counter;
    }
