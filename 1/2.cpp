#include <stdio.h>
#include <limits>
#include <typeinfo>
#include <string>

using namespace std;

template <typename T>
void printType(std::string const &typeName)
{
    int size = 0;
    T lowerLimit = 0;
    T upperLimit = 0;

    size = sizeof(T);
    lowerLimit = std::numeric_limits<T>::min();
    upperLimit = std::numeric_limits<T>::max();

    if (lowerLimit == 0)
        printf("Typ %s hat Speichergröße %d und einen Zahlenbereich von %llu bis %llu \r\n", typeName.c_str(), size, lowerLimit, upperLimit);
    else if (lowerLimit < -3000000000)
        printf("Typ %s hat Speichergröße %d und einen Zahlenbereich von %lld bis %lld \r\n", typeName.c_str(), size, lowerLimit, upperLimit);
    else
        printf("Typ %s hat Speichergröße %d und einen Zahlenbereich von %d bis %d \r\n", typeName.c_str(), size, lowerLimit, upperLimit);
}

void printTypes()
{
    //char
    printType<char>("char");

    //unsigned char
    printType<unsigned char>("unsigned char");

    //short int
    printType<short int>("short int");

    //unsigned short int
    printType<unsigned short int>("unsigned short int");

    //int
    printType<int>("int");

    //unsigned int
    printType<unsigned int>("unsigned int");

    //long int
    printType<long>("long int");

    //unsigned long int
    printType<unsigned long>("unsigned long int");

    //long long int
    printType<long long>("long long int");

    //unsigned long long int
    printType<unsigned long long>("unsigned long long int");
}

int main()
{
    printTypes();
    return 0;
}