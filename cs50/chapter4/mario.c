#include <cs50.h>
#include <stdio.h>

void pyramid (int n);

int main(void)
{
    int height =get_int("height: ");
    pyramid(height);
}

void pyramid (int h)
{
    if (h == 0)
    {
        return;// return 1을 하면 안되는 이유는 반환형이 void이기 때문에
    }

    pyramid(h-1);

    for (int i = 0; i < h ; i++)
    {
        printf("#");
    }printf("\n");
}
