#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("usage : ./jpeg file\n");
    }

    FILE *file =fopen(argv[1],"r");
    if (file == NULL)
    {
        return 1;
    }

    unsigned char bytes[3];
    fread(bytes, 3, 1, file);
    if(bytes[0] == 0xff && bytes[1] == 0xd8 && bytes[2] == 0xff)
    {
        printf("Maybe");
    }
    else
    {
        printf("Not");
    }
}
