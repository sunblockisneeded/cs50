#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage : ./recover [filename]\n");
        return 1;
    }
    //Open file
    FILE *inptr = fopen(argv[1], "r");
    {
        if (inptr == NULL)
        {
            printf("Could not open %s",argv[2]);
            return 1;
        }
    }

    uint8_t buffer[4];

    //find out whether it is jpeg or not
    int counter = 0;
    do
    {if( buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0 ) == 0xe0)
    {
        char filename [8];
        sprintf(filename, "%i.jpg", counter);

        FILE *makeptr = fopen(filename,"w");
        {
            if (makeptr == NULL)
            fclose(makeptr);
            return 1;
        }

        counter++;
    }
    }while (fseek(inptr, 508, SEEK_CUR); == 0)

}
