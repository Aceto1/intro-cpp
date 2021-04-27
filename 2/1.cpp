#include <stdio.h>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    srand(time(NULL));
    int max, tries, correctNumber, guessedNumber = 0;

    printf("Geben sie das Maximum der zufälligen Zahl ein:\n");
    scanf(" %d", &max);

    correctNumber = rand() % (max + 1);

    do
    {
        printf("Geben sie eine Zahl ein:\r\n");
        scanf(" %d", &guessedNumber);

        if (guessedNumber > correctNumber)
            printf("Die geratene Zahl ist größer als die gesuchte Zahl.\n");
        else if (guessedNumber < correctNumber)
            printf("Die geratene Zahl ist kleiner als die gesuchte Zahl.\n");

        tries++;
    } while (guessedNumber != correctNumber);

    printf("Sie haben die Zahl erraten! Sie haben %d Versuche benötigt.", tries);

    return 0;
}