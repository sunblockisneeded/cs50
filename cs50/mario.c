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
                    image[i][j].rgbtRed = round((copy[i-1][j].rgbtRed+copy[i][j+1].rgbtRed+copy[i-1][j+1].rgbtRed + copy[i][j].rgbtRed)/4.0);
                    image[i][j].rgbtGreen = round((copy[i-1][j].rgbtGreen+copy[i][j+1].rgbtGreen+copy[i-1][j+1].rgbtGreen + copy[i][j].rgbtGreen)/4.0);
                    image[i][j].rgbtBlue = round((copy[i-1][j].rgbtBlue+copy[i][j+1].rgbtBlue+copy[i-1][j+1].rgbtBlue) + copy[i][j].rgbtBlue/4.0);
                }
                else
                {
                    image[i][j].rgbtRed = round((copy[i][j-1].rgbtRed + copy[i+1][j+1].rgbtRed + copy[i][j+1].rgbtRed +copy[i+1][j+1].rgbtRed + copy[i+1][j].rgbtRed +copy[i][j].rgbtRed)/6.0);
                    image[i][j].rgbtGreen = round((copy[i][j-1].rgbtGreen + copy[i+1][j+1].rgbtGreen + copy[i][j+1].rgbtGreen +copy[i+1][j+1].rgbtGreen + copy[i+1][j].rgbtGreen +copy[i][j].rgbtGreen)/6.0);
                    image[i][j].rgbtBlue = round((copy[i][j-1].rgbtBlue + copy[i+1][j+1].rgbtBlue + copy[i][j+1].rgbtBlue +copy[i+1][j+1].rgbtBlue + copy[i+1][j].rgbtBlue +copy[i][j].rgbtBlue)/6.0);
                }
            }
            else if (i == height - 1)
            {
                if (j == 0)
                {
                    image[i][j].rgbtRed = round((copy[i+1][j].rgbtRed+copy[i][j-1].rgbtRed+copy[i+1][j-1].rgbtRed + copy[i][j].rgbtRed)/4.0);
                    image[i][j].rgbtGreen = round((copy[i+1][j].rgbtGreen+copy[i][j-1].rgbtGreen+copy[i+1][j-1].rgbtGreen + copy[i][j].rgbtGreen)/4.0);
                    image[i][j].rgbtBlue = round((copy[i+1][j].rgbtBlue+copy[i][j-1].rgbtBlue+copy[i+1][j-1].rgbtBlue + copy[i][j].rgbtBlue)/4.0);
                }
                else if (j == width - 1)
                {
                    image[i][j].rgbtRed = round((copy[i-1][j].rgbtRed+copy[i][j-1].rgbtRed+copy[i-1][j-1].rgbtRed + copy[i][j].rgbtRed)/4.0);
                    image[i][j].rgbtGreen = round((copy[i-1][j].rgbtGreen+copy[i][j-1].rgbtGreen+copy[i-1][j-1].rgbtGreen + copy[i][j].rgbtGreen )/4.0);
                    image[i][j].rgbtBlue = round((copy[i-1][j].rgbtBlue+copy[i][j-1].rgbtBlue+copy[i-1][j-1].rgbtBlue + copy[i][j].rgbtBlue)/4.0);
                }
                else
                {
                    image[i][j].rgbtRed = round((copy[i-1][j].rgbtRed + copy[i-1][j-1].rgbtRed + copy[i][j-1].rgbtRed + copy[i+1][j-1].rgbtRed + copy[i+1][j].rgbtRed + copy[i][j].rgbtRed)/6.0);
                    image[i][j].rgbtGreen = round((copy[i-1][j].rgbtGreen + copy[i-1][j-1].rgbtGreen + copy[i][j-1].rgbtGreen + copy[i+1][j-1].rgbtGreen + copy[i+1][j].rgbtGreen + copy[i][j].rgbtGreen)/6.0);
                    image[i][j].rgbtBlue = round((copy[i-1][j].rgbtBlue + copy[i-1][j-1].rgbtBlue + copy[i][j-1].rgbtBlue + copy[i+1][j-1].rgbtBlue + copy[i+1][j].rgbtBlue + copy[i][j].rgbtBlue)/6.0);
                }
            }
            else if (0 < i && i < height - 1 && j == 0)
            {
                image[i][j].rgbtRed = round((copy[i][j-1].rgbtRed + copy[i+1][j-1].rgbtRed + copy[i+1][j].rgbtRed + copy[i+1][j+1].rgbtRed + copy[i][j+1].rgbtRed + copy[i][j].rgbtRed)/6.0);
                image[i][j].rgbtBlue = round((copy[i][j-1].rgbtBlue + copy[i+1][j-1].rgbtBlue + copy[i+1][j].rgbtBlue + copy[i+1][j+1].rgbtBlue + copy[i][j+1].rgbtBlue + copy[i][j].rgbtBlue)/6.0);
                image[i][j].rgbtGreen = round((copy[i][j-1].rgbtGreen + copy[i+1][j-1].rgbtGreen + copy[i+1][j].rgbtGreen + copy[i+1][j+1].rgbtGreen + copy[i][j+1].rgbtGreen + copy[i][j].rgbtGreen)/6.0);
            }
            else if (0 < i && i < height - 1 && j == width-1)
            {
                image[i][j].rgbtRed = round((copy[i][j-1].rgbtRed + copy[i-1][j-1].rgbtRed + copy[i-1][j].rgbtRed + copy[i-1][j+1].rgbtRed + copy[i][j+1].rgbtRed + copy[i][j].rgbtRed)/6.0);
                image[i][j].rgbtGreen = round((copy[i][j-1].rgbtGreen + copy[i-1][j-1].rgbtGreen + copy[i-1][j].rgbtGreen + copy[i-1][j+1].rgbtGreen + copy[i][j+1].rgbtGreen + copy[i][j].rgbtGreen)/6.0);
                image[i][j].rgbtBlue = round((copy[i][j-1].rgbtBlue + copy[i-1][j-1].rgbtBlue + copy[i-1][j].rgbtBlue + copy[i-1][j+1].rgbtBlue + copy[i][j+1].rgbtBlue + copy[i][j].rgbtBlue)/6.0);
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


struct abc
{
    char a;            //1바이트
    long long b;       //8바이트
}
