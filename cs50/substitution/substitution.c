#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc != 2) //이 조건을 넣지 않으면 argv[1]이 정의되지 않음으로 core dump 발생
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    int len = strlen(argv[1]); //입력받은 암호를 encrypt라는 char로 변환
    char encrypt[len];
    for (int i = 0; i < len; i++)
    {
        encrypt[i] = (char) argv[1][i];
        if(encrypt [i] >='a' && encrypt[i]<='z')
        {
            encrypt[i] = (char) argv[1][i]-32;  //소문자라면 암호값을 대문자로 바꿔서 일관성있게 처리
        }
        else
        {
            encrypt[i] = (char) argv[1][i];
        }

        if (isalpha(encrypt[i]) == 0 || len != 26) // isalpha 알파벳이면 0이아닌값, 알파벳 아니면 0
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }
        else if (isalpha(encrypt[i]) == 0 || len == 26) //조건에 부합하면 탈출
        {
        }
        else
        {
            printf("Usage: ./substitution key\n");
            return 1;
        }
    }
    for (int i = 0 ; i<26 ; i++)
    {
        for (int j = i+1 ; j<26 ; j++)
        if(encrypt[i] == encrypt[j])  //암호값이 중복되있는지 평가
        {
            return 1;
        }
    }

    string text = get_string("plaintext: ");
    int textlen = strlen(text);
    char textarr[textlen];   //암호화할 char
    char encrypted[textlen]; //암호화된 값
    for (int i = 0; i < textlen; i++)
    {
        textarr[i] = text[i]; //암호화할 input을 char로 변환
        if (isalpha(textarr[i]) != 0)
        {
            if (islower(textarr[i]) != 0) // islower 소문자면 0이 아닌 값
            {
                encrypted[i] = encrypt[(textarr[i] - 97)];  //소문자라면 대문자로 일관성있게 처리
            }
            else
            {
                encrypted[i] = encrypt[(textarr[i] - 65)];
            }
        }
        else
        {
            encrypted[i] = textarr[i];
        }
    }

    printf("ciphertext: ");
    for (int i = 0; i < textlen; i++)
    {
        if (isalpha(textarr[i]) != 0)
        {
            if (isupper(textarr[i]) == 0)
            {
                printf("%c", encrypted[i] + 32); //대문자로 처리한 것 소문자로 복구
            }
            else
            {
                printf("%c", encrypted[i]);
            }
        }
        else
            printf("%c", encrypted[i]);
    }
    printf("\n");
}
//이 디자인은 암호화된 값이 원본값을 불러와 소문자인지 대문자인지 확인한 후에 복구한다는 점에서 취약점을 가지는 듯.
