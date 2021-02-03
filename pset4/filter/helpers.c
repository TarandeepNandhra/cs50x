#include "helpers.h"
#include <math.h>
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            float sum = ( (float) image[i][j].rgbtRed + (float) image[i][j].rgbtBlue + (float) image[i][j].rgbtGreen ) / 3;
            
            int average = round( sum );
            
            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtBlue = average;
        }
    }
    
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            float u_sepiaRed = .393 * (float) image[i][j].rgbtRed + .769 * (float) image[i][j].rgbtGreen + .189 * (float) image[i][j].rgbtBlue;
            float u_sepiaGreen = .349 * (float) image[i][j].rgbtRed + .686 * (float) image[i][j].rgbtGreen + .168 * (float) image[i][j].rgbtBlue;
            float u_sepiaBlue = .272 * (float) image[i][j].rgbtRed + .534 * (float) image[i][j].rgbtGreen + .131 * (float) image[i][j].rgbtBlue;
            
            int sepiaRed = round(u_sepiaRed);
            int sepiaGreen = round(u_sepiaGreen);
            int sepiaBlue = round(u_sepiaBlue);
            
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
            
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }

    return;
}

//swaps two ints

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < floor(width / 2); j++)
        {
            int a1 = image[i][j].rgbtRed;
            int a2 = image[i][width - j].rgbtRed;
            swap(&a1, &a2);
            image[i][j].rgbtRed = a1;
            image[i][width - j].rgbtRed = a2;

            int b1 = image[i][j].rgbtBlue;
            int b2 = image[i][width - j].rgbtBlue;
            swap(&b1, &b2);
            image[i][j].rgbtBlue = b1;
            image[i][width - j].rgbtBlue = b2;
            
            int c1 = image[i][j].rgbtGreen;
            int c2 = image[i][width - j].rgbtGreen;
            swap(&c1, &c2);
            image[i][j].rgbtGreen = c1;
            image[i][width - j].rgbtGreen = c2;
        }
    }
    
    return;
}

void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // check if value exsists (above height or width and below 0 is invalid)
    // if valid then add value - then divide by number added
    int c = 0;
    int s[3] = {0 , 0, 0};
    
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            // always include itself
            c++;
            s[0]+= image[i][j].rgbtRed;
            s[1]+= image[i][j].rgbtBlue;
            s[2]+= image[i][j].rgbtGreen;
            
            // if top left exsists
            if(i - 1 >= 0 && j - 1 >= 0)
            {
                c++;
                s[0]+= image[i-1][j - 1].rgbtRed;
                s[1]+= image[i-1][j - 1].rgbtBlue;
                s[2]+= image[i-1][j - 1].rgbtGreen;
            }
            
            //if above exsists
            if(i - 1 >= 0)
            {
                c++;
                s[0]+= image[i-1][j].rgbtRed;
                s[1]+= image[i-1][j].rgbtBlue;
                s[2]+= image[i-1][j].rgbtGreen;
            }
            //if top right exists
            if(i - 1 >= 0 && j + 1 <= width)
            {
                c++;
                s[0]+= image[i-1][j + 1].rgbtRed;
                s[1]+= image[i-1][j + 1].rgbtBlue;
                s[2]+= image[i-1][j + 1].rgbtGreen;
            }
            //if left exsists
            if(j - 1 >= 0)
            {
                c++;
                s[0]+= image[i][j - 1].rgbtRed;
                s[1]+= image[i][j - 1].rgbtBlue;
                s[2]+= image[i][j - 1].rgbtGreen;
            }
            //if right exsists
            if(j + 1 <= width)
            {
                c++;
                s[0]+= image[i][j + 1].rgbtRed;
                s[1]+= image[i][j + 1].rgbtBlue;
                s[2]+= image[i][j + 1].rgbtGreen;
            }
            //if bottom left exsists
            if(i + 1 <= height && j - 1 >= 0)
            {
                c++;
                s[0]+= image[i+1][j - 1].rgbtRed;
                s[1]+= image[i+1][j - 1].rgbtBlue;
                s[2]+= image[i+1][j - 1].rgbtGreen;
            }
            //if bottom exsists
            if(i + 1 <= height)
            {
                c++;
                s[0]+= image[i+1][j].rgbtRed;
                s[1]+= image[i+1][j].rgbtBlue;
                s[2]+= image[i+1][j].rgbtGreen;
            }
            //if bottom right exsists
            if(i + 1 <= height && j + 1 <= width)
            {
                c++;
                s[0]+= image[i+1][j + 1].rgbtRed;
                s[1]+= image[i+1][j + 1].rgbtBlue;
                s[2]+= image[i+1][j + 1].rgbtGreen;
            }
            double a_red = ( (double) s[0] / (double) c );
            double a_blue = ( (double) s[1] / (double) c );
            double a_green = ( (double) s[2] / (double) c );
    
            image[i][j].rgbtRed = round(a_red);
            image[i][j].rgbtBlue = round(a_blue);
            image[i][j].rgbtGreen = round(a_green);
        }
    }

    return;
}
