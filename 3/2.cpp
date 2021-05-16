#include <stdio.h>
#include <string>
#include <iostream>
#include <cmath>

bool validateInput(std::string input)
{
    return input == "ja" || input == "nein";
}

bool getInput()
{
    std::string input;

    do
    {
        std::getline(std::cin, input);
    } while (!validateInput(input));

    return input == "ja";
}

void getUpperAndLowerBound(int *lowerBound, int *upperBound)
{
    bool input;
    int newUpperBound = 1;

    do
    {
        *lowerBound = newUpperBound;
        newUpperBound *= 10;
        *upperBound = newUpperBound;

        std::cout << "Ist die Zahl kleiner als " << newUpperBound << "?" << std::endl;
        input = getInput();
    } while (!input);
}

void guessBetween(int *lowerBound, int *upperBound)
{
    bool input = true;
    int newUpperBound;

    do
    {
        if (input)
            newUpperBound = *lowerBound + ceil((*upperBound - *lowerBound) / 2.0f);
        else
            newUpperBound = *upperBound;

        std::cout << "Ist die Zahl zwischen als " << *lowerBound - 1 << " und " << newUpperBound + 1 << "?" << std::endl;
        input = getInput();

        if (input)
        {
            *upperBound = newUpperBound;
        }
        else
        {
            *lowerBound = newUpperBound;
        }
    } while ((*upperBound - *lowerBound) > 4);
}

void guessNumber(int lowerBound, int upperBound) {
    bool input;

    while(lowerBound <= upperBound) {
        std::cout << "Ist die Zahl " << lowerBound << "?" << std::endl;
        input = getInput();

        if(input)
            return;
        else
            lowerBound++;
    }

    std::cout << "Es ist etwas schief gelaufen." << std::endl;
}

int main()
{
    std::cout << "Antwortmöglichkeiten: \"ja\" und \"nein\"." << std::endl;

    int upperBound, lowerBound;

    getUpperAndLowerBound(&lowerBound, &upperBound);

    guessBetween(&lowerBound, &upperBound);

    guessNumber(lowerBound, upperBound);

    return 0;
}