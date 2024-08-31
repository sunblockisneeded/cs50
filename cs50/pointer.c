#include <stdio.h>

int main (void)
{
    char *n = "emma"; //문자열은 문자열의 첫번째 바이트 주소로 정의
    printf("%p\n",&n);  //n이라는 포인터 그 자체의 주소
    printf("%s\n",n);  // emma 배열의 첫번째 글자 e~주소를 나타냄
    printf("%s\n",n+1); // emma 배열의 두번째 글자 m를 나타냄
    printf("%p\n",&n[0]); //n이 나타내는 배열의 1번째 글자 e주소나타냄
    printf("%c\n",*(n+1));
    printf("%p\n",n);
    printf("%p\n", &n[0]);
}

