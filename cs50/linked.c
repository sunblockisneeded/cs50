#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
}node;

int main (int argc, char* argv[])
{
    node* list = NULL;
    node* n = malloc(sizeof(node));
    if (n ==NULL)
    {
        printf("UnkNown ErR0r");
        return 1;
    }
    n -> number = 1;
    n -> next = NULL;
    list = n;

    n = malloc(sizeof(node));
    n -> number = 2;
    n -> next = list;
    list = n;

    n = malloc(sizeof(node));
    n -> number = 3;
    n -> next = list;
    list = n;

    free(n)

}
