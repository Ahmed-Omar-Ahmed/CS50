#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

int main(void)
{
    string message = get_string("Message: ");
    int bitArray[BITS_IN_BYTE];
    int messageLength = strlen(message);

    for (int i = 0; i < messageLength; i++)
    {
        for (int j = 0; j < BITS_IN_BYTE; j++)
        {
            if (message[i] % 2 == 0)
            {
                bitArray[j] = 0;
            }
            else
            {
                bitArray[j] = 1;
            }
            message[i] = message[i] / 2;
        }
        for (int j = 0; j < BITS_IN_BYTE; j++)
        {
            print_bulb(bitArray[7 - j]);
        }

        printf("\n");
    }
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
