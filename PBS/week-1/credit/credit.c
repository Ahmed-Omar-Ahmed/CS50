#include <cs50.h>
#include <stdio.h>

int get_number_of_digits(long long cc);
int *init_number_array(int digitsNumber, long long ccDigits, int *digitsArray);
int get_first_sum(int *digitsArray, int digitNumber);
int get_second_sum(int *digitsArray, int digitNumber);
string type_checker(int *digitsArray, int digitNumber);

int main(void)
{
    long long cc = get_long_long("Card Number: ");

    while (cc < 0)
    {
        cc = get_long_long("Card Number: ");
    }

    int digitNumber = get_number_of_digits(cc);

    int *digitsArray;
    int digitsArrayHolder[digitNumber];
    digitsArray = init_number_array(digitNumber, cc, digitsArrayHolder);

    int first_sum = get_first_sum(digitsArray, digitNumber);
    int second_sum = get_second_sum(digitsArray, digitNumber);
    int sum = first_sum + second_sum;

    if (sum % 10 == 0)
    {
        string type = type_checker(digitsArray, digitNumber);
        printf("%s\n", type);
    }
    else
    {
        printf("INVALID\n");
    }
}

int get_number_of_digits(long long cc)
{
    int counter = 0;
    while (cc > 0)
    {
        cc = cc / 10;
        counter++;
    }

    return counter;
}

int *init_number_array(int digitsNumber, long long ccDigits, int *digitsArrayHolder)
{
    int digit = 0;

    for (int i = 1; i <= digitsNumber; i++)
    {
        digit = ccDigits % 10;
        ccDigits = ccDigits / 10;
        digitsArrayHolder[digitsNumber - i] = digit;
    }

    return digitsArrayHolder;
}

int get_first_sum(int *digitsArray, int digitNumber)
{
    int sum = 0;

    for (int i = 0; i < digitNumber; i = i + 2)
    {

        if (digitNumber - 2 - i >= 0)
        {
            int digit = digitsArray[digitNumber - 2 - i];
            int digitTotal = 0;
            if (digit * 2 > 9)
            {
                digitTotal = (digit * 2) % 10 + (digit * 2 / 10);
            }
            else
            {
                digitTotal = digit * 2;
            }
            sum = sum + digitTotal;
        }
    }

    return sum;
}

int get_second_sum(int *digitsArray, int digitNumber)
{
    int sum = 0;

    for (int i = 0; i < digitNumber; i = i + 2)
    {

        if (digitNumber - i >= 0)
        {
            int digit = digitsArray[digitNumber - i - 1];
            sum = sum + digit;
        }
    }

    return sum;
}

string type_checker(int *digitsArray, int digitNumber)
{
    if ((digitNumber == 13 || digitNumber == 16) && (digitsArray[0] == 4))
    {
        return "VISA";
    }
    else if ((digitNumber == 16) && (digitsArray[0] == 5) &&
             (digitsArray[1] == 1 || digitsArray[1] == 2 || digitsArray[1] == 3 || digitsArray[1] == 4 || digitsArray[1] == 5))
    {
        return "MASTERCARD";
    }
    else if ((digitsArray[0] == 3) && (digitsArray[1] == 4 || digitsArray[1] == 7))
    {
        return "AMEX";
    }
    else
    {
        return "INVALID";
    }
}