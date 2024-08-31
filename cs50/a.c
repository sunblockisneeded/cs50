#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    char* a = get_string("a: ");
    char* b = get_string("b: ");

    if(strlen(a) != strlen(b))
    {
        printf("different\n");
        return 1;
    }
    for (int i =0, len = strlen(a); i < len+1 ; i++)
    {
        if(a[i] != b[i]) // *(a+(i)) 와 *(b+(i))도 같은의미
        {
            printf("different\n");
            return 1;
        }
    }
        printf("same\n");
        return 0;

}
