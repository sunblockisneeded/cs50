#include <stdio.h>
#include <cs50.h>
#include <string.h>

typedef struct
{
    string name;
    string number;
}people;


int main(void)
{
    people person[4];
    person[0].name = "EMMA";
    person[0].number= "010-1111-1111";

    person[1].name = "RODRIGO";
    person[1].number = "010-2222-2222";

    person[2].name = "HIM";
    person[2].number = "010-3333-3333";

    person[3].name = "HER";
    person[3].number = "010-4444-4444";

    //귀찮은데 값을 묶어서 저장할 수 있음. 이름순으로 바꿔도
    //자료의 혼동이 오지 않을 것임. : 캡슐화가 필요
    string ask = get_string("Find who?: ");
    for (int i =0 ; i < 4; i++)
    {
        if (strcmp(person[i].name , ask ) ==0)
        {
            printf("Number: %s\n",person[i].number);
        }
    }return 0;
    printf("Not found\n");
    return 1;
}
