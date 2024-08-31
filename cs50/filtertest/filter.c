#include <stdio.h>
#include <getopt.h>
#include <stdlib.h>

{
    int main(int argc, char *argv[])

    char *filters = 'bgrs';

    char filter = getopt(argc, argv, filters);
    if (filter == '?')
    {
        printf("Invalid Filter.\n");
        return 1;    }

    if(getopt(argc,argv,filters) != -1)
    {
        printf("Only one filter allowed.\n");
        return 2;
    }

    if(argc != optind + 2) //필터를 처리한 후 인풋/ 아웃풋 2개가 남아있어야 함
    {
     jd   printf("Usage: ./filter [flag] infile outfile\n");
        return 3;
    }

    //remember filename
    char *infile = argv[optind];
    char *outfile = argv[optind + 1];

    FILE *inptr = fopen(infile , "r");
    if(inptr == NULL)
    {
        printf("Could not open %s.\n",infile);
        return 4;
    }

    FILE *outptr = fopen(outfile , "w");
    {
        if(outptr == NULL)
        {
            fclose(inptr); //outptr is already closed
            printf("Could not open %s.\n",outfile);
            return 5;
        }
    }

    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    if (bf.bfType != 0x4d42 || bf.bf0ffBits != 54 || bi.biSize != 40
        bi.biBitCount != 24 || bi.biCompression != 0)
        {
            fclose(outptr);
            fclose(inptr);
            printf("Unsupported file format.\n");
            return 6;
        }

    int height = abs(bi.biHeight);
    int width = bi.biwidth;

    RGBTRIPLE(*image)[width] = calloc(height, width * sizeof(RGBTRIPLE));
    if (image == NULL)
    {
        prinf("Not enough Memory to store image.\n");
        fclose(outptr);
        fclose(inptr);
        return 7;
    }

    int padding = (4- (width *sizeof(RGBTRIPLE)) % 4) % 4;

    for (int i = 0; i < height; i++)
    {
        fread(image[i], sizeof(RGBTRIPLE), width, inptr);

        fseek(inptr, padding, SEEK_CUR);  //fseek(포인터, 수, 위치)
    }

    switch (filter)
    {
        case 'b' :
            blur(height, width, image);
            break;

        case 'g' :
            grayscale(height, width, image);
            break;

        case 'r' :
            reflect(height, width, image);
            break;

        case 's'
            sepia(height, width, image);
            break;
    }

    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    for (int i =0; i < height; i++)
    {
        fwrite(image[i], sizeof(RGBTRIPLE), width, outptr);

        for (int k = 0; k < padding; k++)
        {
            fputc(0x00, outptr);
        }
    }
    free(image);

    fclose(outptr);
    fclose(inptr);
    return 0;
}
