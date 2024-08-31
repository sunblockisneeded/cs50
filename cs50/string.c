#include <stdio.h>

int main (void)

{
    char y[5];
    printf("y:");
    scanf("%s",y); //scanf는 y의 첫 바이트 주소를 넘겨줌
    // &y[0]과 같은 의미이다. y = &y[0]과 같음으로 그냥 y를 쓰자
    printf("y: %s\n",y);
}
