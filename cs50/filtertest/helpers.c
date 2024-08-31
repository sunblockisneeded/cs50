#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0 ; i < height ; i++)
    {
        for (int j = 0 ; j < width ; j++)
        {
            //해당 픽셀의 rgb값 얻기
            int gray = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue)/3.0);
            //update pixel values
            image[i][j].rgbtRed = gray;
            image[i][j].rgbtGreen = gray;
            image[i][j].rgbtBlue = gray;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0 ; i < height ; i++)
    {
        for (int j = 0 ; j < width ; j++)
        {
            //해당 픽셀의 rgb값 얻기
            int sepiaRed = round(0.393 *image[i][j].rgbtRed + 0.769 * image[i][j].rgbtGreen + 0.189* image[i][j].rgbtBlue);
            int sepiaGreen = round(0.349 *image[i][j].rgbtRed + 0.686 * image[i][j].rgbtGreen + 0.168 * image[i][j].rgbtBlue);
            int sepiaBlue = round(0.272 *image[i][j].rgbtRed + 0.534 * image[i][j].rgbtGreen + 0.131 * image[i][j].rgbtBlue);

            //sepia 가 255보다 큰 경우 보정
            if(sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            if(sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            if(sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }
            //update pixel values
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE buffer[height][width];
    for (int i = 0; i < height ; i++)
    {

        for (int j = 0; j < width ; j++)
        {
            buffer[i][j] = image[i][j];
        }
    }
    for (int i = 0; i < height ; i++)
    {

        for (int j = 0; j < width ; j++)
        {
            image[i][j] = buffer[i][width- j - 1];
        }
    }


    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height ; i++)
    {
        for (int j =0; j < width ; j++)
        {
            copy[i][j] = image [i][j];
        }
    }

    for (int i = 0; i < height ; i++)
    {
        for (int j = 0; j < width ; j++)
        {
            if(i == 0)
            {
                if(j == 0)
                {
                    image[i][j].rgbtRed = round((copy[i+1][j].rgbtRed+copy[i][j+1].rgbtRed+copy[i+1][j+1].rgbtRed + copy[i][j].rgbtRed)/4.0);
                    image[i][j].rgbtGreen = round((copy[i+1][j].rgbtGreen+copy[i][j+1].rgbtGreen+copy[i+1][j+1].rgbtGreen + copy[i][j].rgbtGreen)/4.0);
                    image[i][j].rgbtBlue = round((copy[i+1][j].rgbtBlue+copy[i][j+1].rgbtBlue+copy[i+1][j+1].rgbtBlue + copy[i][j].rgbtBlue)/4.0);
                }
                else if(j == width -1)
                {
                    image[i][j].rgbtRed = round((copy[i][j-1].rgbtRed+copy[i+1][j-1].rgbtRed+copy[i+1][j].rgbtRed + copy[i][j].rgbtRed)/4.0);
                    image[i][j].rgbtGreen = round((copy[i][j-1].rgbtGreen+copy[i+1][j-1].rgbtGreen+copy[i+1][j].rgbtGreen + copy[i][j].rgbtGreen)/4.0);
                    image[i][j].rgbtBlue = round((copy[i][j-1].rgbtBlue+copy[i+1][j-1].rgbtBlue+copy[i+1][j].rgbtBlue + copy[i][j].rgbtBlue)/4.0);
                }
                else
                {
                    image[i][j].rgbtRed = round((copy[i][j-1].rgbtRed + copy[i+1][j-1].rgbtRed + copy[i+1][j].rgbtRed +copy[i+1][j+1].rgbtRed + copy[i][j+1].rgbtRed +copy[i][j].rgbtRed)/6.0);
                    image[i][j].rgbtGreen = round((copy[i][j-1].rgbtGreen + copy[i+1][j-1].rgbtGreen + copy[i+1][j].rgbtGreen +copy[i+1][j+1].rgbtGreen + copy[i][j+1].rgbtGreen +copy[i][j].rgbtGreen)/6.0);
                    image[i][j].rgbtBlue = round((copy[i][j-1].rgbtBlue + copy[i+1][j-1].rgbtBlue + copy[i+1][j].rgbtBlue +copy[i+1][j+1].rgbtBlue + copy[i][j+1].rgbtBlue +copy[i][j].rgbtBlue)/6.0);
                }
            }
            else if (i == height - 1)
            {
                if (j == 0)
                {
                    image[i][j].rgbtRed = round((copy[i-1][j].rgbtRed+copy[i-1][j+1].rgbtRed+copy[i][j+1].rgbtRed + copy[i][j].rgbtRed)/4.0);
                    image[i][j].rgbtGreen = round((copy[i-1][j].rgbtGreen + copy[i-1][j+1].rgbtGreen + copy[i][j+1].rgbtGreen + copy[i][j].rgbtGreen)/4.0);
                    image[i][j].rgbtBlue = round((copy[i-1][j].rgbtBlue + copy[i-1][j+1].rgbtBlue + copy[i][j+1].rgbtBlue + copy[i][j].rgbtBlue)/4.0);
                }
                else if (j == width - 1)
                {
                    image[i][j].rgbtRed = round((copy[i-1][j].rgbtRed+copy[i][j-1].rgbtRed+copy[i-1][j-1].rgbtRed + copy[i][j].rgbtRed)/4.0);
                    image[i][j].rgbtGreen = round((copy[i-1][j].rgbtGreen+copy[i][j-1].rgbtGreen+copy[i-1][j-1].rgbtGreen + copy[i][j].rgbtGreen )/4.0);
                    image[i][j].rgbtBlue = round((copy[i-1][j].rgbtBlue+copy[i][j-1].rgbtBlue+copy[i-1][j-1].rgbtBlue + copy[i][j].rgbtBlue)/4.0);
                }
                else
                {
                    image[i][j].rgbtRed = round((copy[i][j-1].rgbtRed + copy[i-1][j-1].rgbtRed + copy[i-1][j].rgbtRed + copy[i-1][j+1].rgbtRed + copy[i][j+1].rgbtRed + copy[i][j].rgbtRed)/6.0);
                    image[i][j].rgbtGreen = round((copy[i][j-1].rgbtGreen + copy[i-1][j-1].rgbtGreen + copy[i-1][j].rgbtGreen + copy[i-1][j+1].rgbtGreen + copy[i][j+1].rgbtGreen + copy[i][j].rgbtGreen)/6.0);
                    image[i][j].rgbtBlue = round((copy[i][j-1].rgbtBlue + copy[i-1][j-1].rgbtBlue + copy[i-1][j].rgbtBlue + copy[i-1][j+1].rgbtBlue + copy[i][j+1].rgbtBlue + copy[i][j].rgbtBlue)/6.0);
                }
            }
            else if (0 < i && i < height - 1 && j == 0)
            {
                image[i][j].rgbtRed = round((copy[i-1][j].rgbtRed + copy[i-1][j+1].rgbtRed + copy[i][j+1].rgbtRed + copy[i+1][j+1].rgbtRed + copy[i+1][j].rgbtRed + copy[i][j].rgbtRed)/6.0);
                image[i][j].rgbtGreen = round((copy[i-1][j].rgbtGreen + copy[i-1][j+1].rgbtGreen + copy[i][j+1].rgbtGreen + copy[i+1][j+1].rgbtGreen + copy[i+1][j].rgbtGreen + copy[i][j].rgbtGreen)/6.0);
                image[i][j].rgbtBlue = round((copy[i-1][j].rgbtBlue + copy[i-1][j+1].rgbtBlue + copy[i][j+1].rgbtBlue + copy[i+1][j+1].rgbtBlue + copy[i+1][j].rgbtBlue + copy[i][j].rgbtBlue)/6.0);
            }
            else if (0 < i && i < height - 1 && j == width-1)
            {
                image[i][j].rgbtRed = round((copy[i-1][j].rgbtRed + copy[i-1][j-1].rgbtRed + copy[i][j-1].rgbtRed + copy[i+1][j-1].rgbtRed + copy[i+1][j].rgbtRed + copy[i][j].rgbtRed)/6.0);
                image[i][j].rgbtGreen = round((copy[i-1][j].rgbtGreen + copy[i-1][j-1].rgbtGreen + copy[i][j-1].rgbtGreen + copy[i+1][j-1].rgbtGreen + copy[i+1][j].rgbtGreen + copy[i][j].rgbtGreen)/6.0);
                image[i][j].rgbtBlue = round((copy[i-1][j].rgbtBlue + copy[i-1][j-1].rgbtBlue + copy[i][j-1].rgbtBlue + copy[i+1][j-1].rgbtBlue + copy[i+1][j].rgbtBlue + copy[i][j].rgbtBlue)/6.0);
            }
            else
            {
                image[i][j].rgbtRed = round((copy[i-1][j-1].rgbtRed + copy[i-1][j].rgbtRed + copy[i-1][j+1].rgbtRed + copy[i][j+1].rgbtRed + copy[i+1][j+1].rgbtRed + copy[i+1][j].rgbtRed + copy[i+1][j-1].rgbtRed + copy[i][j-1].rgbtRed + copy[i][j].rgbtRed)/9.0);
                image[i][j].rgbtGreen = round((copy[i-1][j-1].rgbtGreen + copy[i-1][j].rgbtGreen + copy[i-1][j+1].rgbtGreen + copy[i][j+1].rgbtGreen + copy[i+1][j+1].rgbtGreen + copy[i+1][j].rgbtGreen + copy[i+1][j-1].rgbtGreen + copy[i][j-1].rgbtGreen + copy[i][j].rgbtGreen)/9.0);
                image[i][j].rgbtBlue = round((copy[i-1][j-1].rgbtBlue + copy[i-1][j].rgbtBlue + copy[i-1][j+1].rgbtBlue + copy[i][j+1].rgbtBlue + copy[i+1][j+1].rgbtBlue + copy[i+1][j].rgbtBlue + copy[i+1][j-1].rgbtBlue + copy[i][j-1].rgbtBlue + copy[i][j].rgbtBlue)/9.0);
            }
        }
    }

    return;
}
