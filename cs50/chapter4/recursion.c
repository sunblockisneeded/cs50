#include <stdio.h>
#include <cs50.h>

void draw (int h);
int main (void)
{
    int height = get_int("Height: ");

    draw(height);
}

//재귀 : 피라미드는 피라미드 그 자체에 1줄을 더한 것
void draw (int h)
{
    if (h == 0)
    {
        return;
    }

    draw(h-1);
    
    for (int i =0 ; i < h ; i++)
    {
        printf("#");
    }
    printf("\n");
}
