#include <stdio.h>
#include <stdlib.h>

void f (void)
{
    char *x = malloc(10 * sizeof(int)); //사이즈만큼 할당, 그것을 x라는 포인터에 저장
    x[9] = 0; // NULL 즉 \0이 저장됨. X[]배열의 9번째까지만 출력될수도
    x[9] = 65; //A가 저장됨

    free(x);
}

int main(void)
{
    f();
    return 0;
}
