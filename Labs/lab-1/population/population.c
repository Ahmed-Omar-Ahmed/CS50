#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int startPopulation = 0;
    do
    {
        startPopulation = get_int("Start size: ");
    } while (startPopulation < 9);
    int endPopulation = 0;
    do
    {
        endPopulation = get_int("End size: ");
    } while (endPopulation < startPopulation);
    int population = startPopulation;
    int years = 0;
    while (population < endPopulation)
    {
        population = population + (population / 3) - (population / 4);
        years++;
    }
    printf("Years: %i\n", years);
}
