#include <cs50.h>
#include <stdio.h>
#include <stdint.h>

int main (argc, argv[])
{
    string name = argv[1];
    FILE *f = fopen("name","r");
    uint8_t buffer[4];
    fread(buffer, 1, 4, f) //filename 이 아닌 filename 과 연결된 포인터 사용중
    //fread 반환값으로 읽은 바이트수를 return
    for (int i =0 ; i < 4; i++)
    {
        printf("%i\n",buffer[i]);
    }
    fclose(f);
}
//fwrite(buffer, 1, 4, f);
//버퍼에서 파일로 쓸 수 있음.\
