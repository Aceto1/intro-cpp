#include <stdio.h>
#include <cmath>
#include <sstream>
#include <iostream>

int ggt(int numerator, int denomirator)
{
    if (denomirator == 0)
    {
        return abs(numerator);
    }
    else
        return ggt(denomirator, numerator % denomirator);
}

void kuerzen(int *z, int *n)
{
    if(*n < 0) {
        *n = abs(*n);
        *z *= -1;
    }

    int g = ggt(*z, *n);
    *z = *z / g;
    *n = *n / g;
}

int main()
{
    int z, n;

    while (1)
    {
        std::cout << "Geben sie Zähler und Nenner des Bruches ein:" << std::endl;
        
        std::string input;
        std::getline(std::cin, input);
        std::stringstream s(input);

        s >> z >> n;

        if(n == 0){
            std::cout << "Der Nenner darf nicht 0 sein." << std::endl;
            continue;
        }

        kuerzen(&z, &n);

        std::cout << "Der normalisierte Bruch: " << z << "/" << n << std::endl;
    }

    return 0;
}