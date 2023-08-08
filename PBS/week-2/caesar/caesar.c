#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int aValue;
int zValue;

bool is_number(string key);
string encrypt_message(int key, string message);

int main(int argc, string argv[])
{
    if (!(argc == 2) || !is_number(argv[1]))
    {
        printf("Usage: ./caesar key");
        return 1;
    }
    int key = atoi(argv[1]) % 26;
    string message = get_string("plaintext:  ");
    string encryptedMessage = encrypt_message(key, message);
    printf("ciphertext: %s\n", encryptedMessage);
}

bool is_number(string key)
{
    for (int i = 0; i < strlen(key); i++)
    {
        if (!isdigit(key[i]))
        {
            return false;
        }
    }
    return true;
}

string encrypt_message(int key, string message)
{
    for (int i = 0; i < strlen(message); i++)
    {
        if (isalpha(message[i]) == 0)
        {
            message[i] = message[i];
        }
        else
        {
            if (!(islower(message[i]) == 0))
            {
                aValue = 97;
                zValue = 122;
            }
            else
            {
                aValue = 65;
                zValue = 90;
            }
            if (message[i] + key > zValue)
            {
                message[i] = aValue + (key - (zValue - message[i] + 1));
            }
            else
            {
                message[i] = message[i] + key;
            }
        }
    }

    return message;
}