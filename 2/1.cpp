#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <iostream>

int main()
{
    srand(time(NULL));
    int max, tries, correctNumber, guessedNumber = 0;

    std::cout << "Geben sie das Maximum der zufälligen Zahl ein:" << std::endl;
    std::cin >> max;

    correctNumber = rand() % (max + 1);

    do
    {
        std::cout << "Geben sie eine Zahl ein:" << std::endl; 
        std::cin >> guessedNumber;

        if (guessedNumber > correctNumber)
            std::cout << "Die geratene Zahl ist größer als die gesuchte Zahl." << std::endl;
        else if (guessedNumber < correctNumber)
            std::cout << "Die geratene Zahl ist kleiner als die gesuchte Zahl." << std::endl;

        tries++;
    } while (guessedNumber != correctNumber);

    std::cout << "Sie haben die Zahl erraten! Sie haben " << tries << " Versuche benötigt." << std::endl;

    return 0;
}