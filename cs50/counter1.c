#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <cs50.h>

int count_letters(string text);

int main(void)
{
    string texts = get_string("Text: ");
    count_letters (texts);
    printf("%i letters",count_letters(texts));
}


int count_letters(string text)
    {
    int len = strlen(text);
    char a[len];
    for (int i = 0 ; i <len ; i++ )
    {
        a[i] = (char)text[i];
    }
    int counter = 0;
    for(int i = 0 ; i< len ; i++)
    {
        if( a[i] == '?' || a[i] == '!' || a[i] == '.')
        {
            counter ++;
        }

    }
    return counter;
    }
