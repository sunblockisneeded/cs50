#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

int main (void)
{
    int *t = malloc(5*sizeof(int));
    for(int i = 0; i<5 ; i++)
    {
        t[i] = get_int("int%i: ",i);
    }

    free(t);  //할당해제 !!

    for (int i =0; i<5 ;i++)
    {
        printf("t %i: %i\n",i,t[i]);  //할당해제 후 t[i]값 출력
    }

}
