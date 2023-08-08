#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;

    do
    {
        height = get_int("Height: ");
    }
    while (height <= 0 || height > 8);

    for (int i = 0; i < height; i++)
    {
        for (int s = 1; s < height - i; s++)
        {
            printf(" ");
        }
        for (int c = 0; c < 2; c++)
        {
            for (int j = 0; j <= i; j++)
            {
                printf("#");
            }
            if (c == 0)
            {
                printf("  ");
            }
        }

        printf("\n");
    }
}