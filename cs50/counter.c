#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int main (void)
{
    string sentence = get_string("write: ");
    int len = strlen(sentence) ;
    char a[len];
    for (int i = 0 ; i <len ; i++ )
    {
        a[i] = (char)sentence[i];
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
    printf("%i\n",counter);
}
