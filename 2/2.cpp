#include <stdio.h>
#include <cmath>
#include <array>

using namespace std;

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
        return result;
    }
    else if (determinante == 0)
    {
        result.at(0) = -(p / 2.0f);
        return result;
    }

    result.at(0) = -(p / 2.0f) + sqrt(determinante);
    result.at(1) = -(p / 2.0f) - sqrt(determinante);

    return result;
}

int main()
{
    int a, b, c;
    printf("Geben sie die drei Koeffizienten an:\n");
    scanf(" %d %d %d", &a, &b, &c);

    std::array<double, 2> result = solve(a, b, c);

    if (result.empty())
        printf("Es gibt keine Lösungen.");
    else if (result.size() == 1)
        printf("Lösung: %g", result.at(0));
    else
    {
        printf("Lösung 1: %g \r\n", result.at(0));
        printf("Lösung 2: %g", result.at(1));
    }

    return 0;
}