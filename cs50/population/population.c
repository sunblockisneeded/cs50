#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int start;
    do
    {
        start = get_int("Start size: ");
    }
    while (start < 9);

    int end;
    do
    {
        end = get_int("End size: ");
    }
    while (end < start);

    int n = start;
    int Years;
    for (Years = 0; n < end; Years++)
    {
        n = n + n / 3 - n / 4;
    }

    printf("Years: %i\n", Years);
}
