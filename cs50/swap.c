#include <stdio.h>

void swap (int *a, int *b);

int main (void)
{
    int x = 1;
    int y = 2;
    swap(&x, &y);
    printf(" %i %i \n", x, y); //2와 1이 출력되어야 함.
}

void swap (int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
