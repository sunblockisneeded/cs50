#include <stdio.h>
#include <cs50.h>

float average (int length, int array[]);

int main(void)
{
    int n = get_int ("how many n: ");

    int scores[n];

    for (int i =0; i < n; i++)
    {
        scores[i] = get_int("scores of subject %i:",i+1);
    }
    printf("average is %.2f\n,", average(n,scores));
}

float average (int length, int array[])
{
    int sum = 0;
    for (int i =0; i < length ; i++)
    {
        sum += array[i];
    }
    return sum/(float)length;
}
