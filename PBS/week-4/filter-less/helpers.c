#include "helpers.h"
#include <math.h>
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int average = 0;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            average = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);
            image[i][j].rgbtBlue = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtRed = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sepianRed = round(0.393 * image[i][j].rgbtRed + 0.769 * image[i][j].rgbtGreen + 0.189 * image[i][j].rgbtBlue);
            int sepianGreen = round(0.349 * image[i][j].rgbtRed + 0.686 * image[i][j].rgbtGreen + 0.168 * image[i][j].rgbtBlue);
            int sepianBlue = round(0.272 * image[i][j].rgbtRed + 0.534 * image[i][j].rgbtGreen + 0.131 * image[i][j].rgbtBlue);
            image[i][j].rgbtRed = (sepianRed > 255) ? 255 : sepianRed;
            image[i][j].rgbtGreen = (sepianGreen > 255) ? 255 : sepianGreen;
            image[i][j].rgbtBlue = (sepianBlue > 255) ? 255 : sepianBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        RGBTRIPLE revRow[width];
        for (int j = 0; j < width; j++)
        {
            revRow[width - j - 1] = image[i][j];
        }
        for (int c = 0; c < width; c++)
        {
            image[i][c] = revRow[c];
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int upperLayerSum[] = {0, 0, 0};
            int middleLayerSum[] = {0, 0, 0};
            int lowerLayerSum[] = {0, 0, 0};
            float entryCounts = 0.0;
            int blurRadius = 3;
            for (int c = 0; c < blurRadius; c++)
            {
                if (!(i < 1) && !(j + c < 1) && !(j + c > width))
                {
                    entryCounts++;
                    upperLayerSum[0] = upperLayerSum[0] + copy[i - 1][j - 1 + c].rgbtRed;
                    upperLayerSum[1] = upperLayerSum[1] + copy[i - 1][j - 1 + c].rgbtGreen;
                    upperLayerSum[2] = upperLayerSum[2] + copy[i - 1][j - 1 + c].rgbtBlue;
                }
            }
            for (int c = 0; c < blurRadius; c++)
            {
                if (!(j + c < 1) && !(j + c > width))
                {
                    entryCounts++;
                    middleLayerSum[0] = middleLayerSum[0] + copy[i][j - 1 + c].rgbtRed;
                    middleLayerSum[1] = middleLayerSum[1] + copy[i][j - 1 + c].rgbtGreen;
                    middleLayerSum[2] = middleLayerSum[2] + copy[i][j - 1 + c].rgbtBlue;
                }
            }
            for (int c = 0; c < blurRadius; c++)
            {
                if (!(i + 2 > height) && !(j + c < 1) && !(j + c > width))
                {
                    entryCounts++;
                    lowerLayerSum[0] = lowerLayerSum[0] + copy[i + 1][j - 1 + c].rgbtRed;
                    lowerLayerSum[1] = lowerLayerSum[1] + copy[i + 1][j - 1 + c].rgbtGreen;
                    lowerLayerSum[2] = lowerLayerSum[2] + copy[i + 1][j - 1 + c].rgbtBlue;
                }
            }
            int redAvg = round((upperLayerSum[0] + middleLayerSum[0] + lowerLayerSum[0]) / entryCounts);
            int greenAvg = round((upperLayerSum[1] + middleLayerSum[1] + lowerLayerSum[1]) / entryCounts);
            int blueAvg = round((upperLayerSum[2] + middleLayerSum[2] + lowerLayerSum[2]) / entryCounts);
            image[i][j].rgbtRed = redAvg;
            image[i][j].rgbtGreen = greenAvg;
            image[i][j].rgbtBlue = blueAvg;
        }
    }
    return;
}
