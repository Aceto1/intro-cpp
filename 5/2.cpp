#include <iostream>
#include <string>
#include <vector>

void readInput(std::vector<std::string> *strings, std::vector<std::string *> *stringVectors)
{
  std::cout << "\".\" eingeben, um die Eingabe zu beenden." << std::endl;

  std::string input;
  while (true)
  {
    std::cout << "Geben Sie eine Zeichenkette ein:" << std::endl;
    std::cin >> input;

    if (input.compare(".") == 0)
      break;

    strings->push_back(input);
    int size = strings->size();
    std::string *value = &(strings->at(size - 1));
    stringVectors->push_back(new std::string(*value));
  }
}

//Insertionsort
void sort(std::vector<std::string *> *strings)
{
  for (int i = 1; i < strings->size(); i++)
  {
    std::string *key = strings->at(i);
    int j = i;
    while (j > 0 && strings->at(j - 1)->compare(*key) > 0)
    {
      strings->at(j) = strings->at(j - 1);
      j--;
    }
    strings->at(j) = key;
  }
}

void printArray(const std::vector<std::string*> stringVectors) {
  for (int i = 0; i < stringVectors.size(); i++)
  {
    std::string *value = stringVectors[i];
    std::cout << *value << std::endl;
  }  
}

int main()
{
  std::vector<std::string> strings = std::vector<std::string>(0);
  std::vector<std::string *> stringVectors = std::vector<std::string *>(0);

  readInput(&strings, &stringVectors);

  sort(&stringVectors);

  std::cout << "Ergebnis der Sortierung: " << std::endl;
  printArray(stringVectors);

  return 0;
}