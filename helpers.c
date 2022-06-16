#include "helpers.h"
#include<math.h>
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])

{ // Iterate over height
    for (int h = 0; h < height; h++)
    {
        // Iterare over width
        for (int w = 0; w < width; w++)
        {
            // Calculate the average of rgbt
            int t = round((image[h][w].rgbtBlue + image[h][w].rgbtGreen + image[h][w].rgbtRed)/3.0);

            // Update rgbt
            image[h][w].rgbtBlue = t;
            image[h][w].rgbtGreen = t;
            image[h][w].rgbtRed = t;
        }
}
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{for (int i = 0; i <= height; i++)
{
for (int j = 0; j <= width - 1; j++)
{

BYTE originalRed = image[i][j].rgbtRed;
BYTE originalGreen = image[i][j].rgbtGreen;
BYTE originalBlue = image[i][j].rgbtBlue;

float sepiaRed = .393 * originalRed + .769 * originalGreen + .189 * originalBlue;
float sepiaGreen = .349 * originalRed + .686 * originalGreen + .168 * originalBlue;
float sepiaBlue = .272 * originalRed + .534 * originalGreen + .131 * originalBlue;

int sR = roundf(sepiaRed);
int sG = roundf(sepiaGreen);
int sB = roundf(sepiaBlue);

if(sR > 255)
{
sR = 255;
}

 if(sG > 255)
{
sG = 255;
}

if(sB > 255)
{
sB = 255;
}
image[i][j].rgbtRed = sR;
image[i][j].rgbtGreen = sG;
image[i][j].rgbtBlue = sB;
}
}
return;
    return;
}

// Reflect image horizontally

   void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        if (width % 2 == 0)
        {
            for (int j = 0; j < width/2; j++)
            {
                RGBTRIPLE temp = image[i][j];
                image[i][j] = image[i][width - j-1];
                image[i][width - j-1] = temp;
            }
        }
        else
        {
            for (int j = 0; j < (width - 1)/2; j++)
            {
                RGBTRIPLE temp = image[i][j];
                image[i][j] = image[i][width - j-1];
                image[i][width - j-1] = temp;
            }
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE ogImage[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            ogImage[i][j] = image[i][j];
        }
    }

    for (int i = 0, red, green, blue, counter; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            red = green = blue = counter = 0;

            if (i >= 0 && j >= 0)
            {
                red += ogImage[i][j].rgbtRed;
                green += ogImage[i][j].rgbtGreen;
                blue += ogImage[i][j].rgbtBlue;
                counter++;
            }
            if (i >= 0 && j - 1 >= 0)
            {
                red += ogImage[i][j-1].rgbtRed;
                green += ogImage[i][j-1].rgbtGreen;
                blue += ogImage[i][j-1].rgbtBlue;
                counter++;
            }
            if ((i >= 0 && j + 1 >= 0) && (i >= 0 && j + 1 < width))
            {
                red += ogImage[i][j+1].rgbtRed;
                green += ogImage[i][j+1].rgbtGreen;
                blue += ogImage[i][j+1].rgbtBlue;
                counter++;
            }
            if (i - 1 >= 0 && j >= 0)
            {
                red += ogImage[i-1][j].rgbtRed;
                green += ogImage[i-1][j].rgbtGreen;
                blue += ogImage[i-1][j].rgbtBlue;
                counter++;
            }
            if (i - 1 >= 0 && j - 1 >= 0)
            {
                red += ogImage[i-1][j-1].rgbtRed;
                green += ogImage[i-1][j-1].rgbtGreen;
                blue += ogImage[i-1][j-1].rgbtBlue;
                counter++;
            }
            if ((i - 1 >= 0 && j + 1 >= 0) && (i - 1 >= 0 && j + 1 < width))
            {
                red += ogImage[i-1][j+1].rgbtRed;
                green += ogImage[i-1][j+1].rgbtGreen;
                blue += ogImage[i-1][j+1].rgbtBlue;
                counter++;
            }
            if ((i + 1 >= 0 && j >= 0) && (i + 1 < height && j >= 0))
            {
                red += ogImage[i+1][j].rgbtRed;
                green += ogImage[i+1][j].rgbtGreen;
                blue += ogImage[i+1][j].rgbtBlue;
                counter++;
            }
            if ((i + 1 >= 0 && j - 1 >= 0) && (i + 1 < height && j - 1 >= 0))
            {
                red += ogImage[i+1][j-1].rgbtRed;
                green += ogImage[i+1][j-1].rgbtGreen;
                blue += ogImage[i+1][j-1].rgbtBlue;
                counter++;
            }
            if ((i + 1 >= 0 && j + 1 >= 0) && (i + 1 < height && j + 1 < width))
            {
                red += ogImage[i+1][j+1].rgbtRed;
                green += ogImage[i+1][j+1].rgbtGreen;
                blue += ogImage[i+1][j+1].rgbtBlue;
                counter++;
            }

            image[i][j].rgbtRed = round(red / (counter * 1.0));
            image[i][j].rgbtGreen = round(green / (counter * 1.0));
            image[i][j].rgbtBlue = round(blue / (counter * 1.0));
        }
    }

    return;
}
