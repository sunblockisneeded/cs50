#include <stdio.h>
#include <cs50.h>
#include <string.h>

typedef struct position
{
    int X;
    int Y;
} pos;

int main(void)
{
    pos mouse[1];
    mouse [0].X = 148;
    mouse [0].Y = 67;
    printf("x: %i\ny: %i\n ",mouse[0].X,mouse[0].Y);
}

