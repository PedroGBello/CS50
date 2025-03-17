#include "helpers.h"
#include <math.h>
#include <stdbool.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop through each pixel:
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Find average between RGB values:
            int average_RGB = round(
                (image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / (float) 3);
            image[i][j].rgbtRed = average_RGB;
            image[i][j].rgbtGreen = average_RGB;
            image[i][j].rgbtBlue = average_RGB;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop through each pixel:
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Sepia algorithm:
            int sepiaRed = round(image[i][j].rgbtRed * 0.393 + image[i][j].rgbtGreen * 0.769 +
                                 image[i][j].rgbtBlue * 0.189);
            int sepiaGreen = round(image[i][j].rgbtRed * 0.349 + image[i][j].rgbtGreen * 0.686 +
                                   image[i][j].rgbtBlue * 0.168);
            int sepiaBlue = round(image[i][j].rgbtRed * 0.272 + image[i][j].rgbtGreen * 0.534 +
                                  image[i][j].rgbtBlue * 0.131);

            if (sepiaRed > 255)
                sepiaRed = 255;
            if (sepiaGreen > 255)
                sepiaGreen = 255;
            if (sepiaBlue > 255)
                sepiaBlue = 255;

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
    // If length is odd or even...
    int mid_width = (width % 2 == 1) ? width / 2 : (width - 1) / 2;

    // Loop through each pixel:
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j <= mid_width; j++)
        {
            // Swap pixels
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Create a copy of image
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    // Select adjacent pixels and find average_RGB including the center
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            const int GRID = 3;

            int sum_rgbtRed = 0;
            int sum_rgbtGreen = 0;
            int sum_rgbtBlue = 0;

            int count = 0;

            // loop through the 3x3 GRID
            for (int x = 0; x < GRID; x++)
            {
                for (int y = 0; y < GRID; y++)
                {
                    int ii = i - 1 + x;
                    int jj = j - 1 + y;

                    if ((ii < 0) || (ii >= height))
                        continue;
                    if ((jj < 0) || (jj >= width))
                        continue;

                    sum_rgbtRed += copy[ii][jj].rgbtRed;
                    sum_rgbtGreen += copy[ii][jj].rgbtGreen;
                    sum_rgbtBlue += copy[ii][jj].rgbtBlue;

                    count++;
                }
            }

            image[i][j].rgbtRed = round(sum_rgbtRed / (float) count);
            image[i][j].rgbtGreen = round(sum_rgbtGreen / (float) count);
            image[i][j].rgbtBlue = round(sum_rgbtBlue / (float) count);
        }
    }
    return;
}
