#include <stdio.h>
#include <cmath>
#include <array>
#include <iostream>

std::array<double, 2> solve(double a, double b, double c)
{
    std::array<double, 2> result = {};
    double p, q;
    if (a > 1)
    {
        p = b / a;
        q = c / a;
    }
    else
    {
        p = b;
        q = c;
    }

    double determinante = pow((p / 2.0f), 2) - q;

    if (determinante < 0)
    {
        result.at(0) = NAN;
        result.at(1) = NAN;
        return result;
    }
    else if (determinante == 0)
    {
        result.at(0) = -(p / 2.0f);
        result.at(1) = NAN;
        return result;
    }

    result.at(0) = -(p / 2.0f) + sqrt(determinante);
    result.at(1) = -(p / 2.0f) - sqrt(determinante);

    return result;
}

int main()
{
    int a, b, c;
    std::cout << "Geben sie die drei Koeffizienten an:\n" << std::endl;
    std::cin >> a >> b >> c;

    std::array<double, 2> result = solve(a, b, c);

    if (std::isnan(result[0]))
        std::cout << "Es gibt keine Lösungen." << std::endl;
    else if (std::isnan(result[1]))
        std::cout << "Lösung: " << result.at(0) << std::endl;
    else
    {
        std::cout << "Lösung 1: " << result.at(0) << std::endl;
        std::cout << "Lösung 2: " << result.at(1) << std::endl;
    }

    return 0;
}