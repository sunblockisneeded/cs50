#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
int n = 5 ;
int arr[5] = {44, 36, 23, 1, 45};
int arr1[1] ={0};
int main (void)
{
    for (int i = 0 ; i < n-1 ; i++)
    {
        for(int j = 0; j < n-1-i ;j++)
        {if (arr[j] < arr[j+1])
        {
            arr1[0] = arr[j+1];
            arr[j+1] = arr[j];
            arr[j] = arr1[0];
        }}
    }
    for (int i = 0; i < n ; i++){
    printf("%i\n",arr[i]);}
}
