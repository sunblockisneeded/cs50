#include <stdio.h>
#include <cs50.h>

int get_width(void);
void block (int n);

int main (void)  //main 함수 : 크기를 묻는 함수 실행 > 그 크기만큼 # 생성
{
    int n = get_width();
    block(n);
}

// 크기를 묻는 함수 n이 1보다 작을 시 계속 되물음
int get_width (void)
   {
    int n;
    do
    {
        n = get_int("width: ");
    }while (n< 1);
    return n;
   }

// n번만큼 블럭 만드는 함수.
void block (int n)
{
    for (int i = 0 ; i < n ; i ++)
    {
        printf("#");
    }
    printf("\n");
}
