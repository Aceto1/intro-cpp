#include <iostream>
#include <string>
#include <vector>

std::vector<std::string *> readVector()
{
  std::cout << "Geben Sie die Zeichenketten getrennt durch Leerzeichen ein:" << std::endl;
  std::string input;
  std::cin.clear();
  std::cin.sync();
  std::getline(std::cin, input);

  std::string inputs[input.length()];
  int stringCount = 0;

  for (int i = 0; i < input.length(); i++)
  {
    if (input[i] == ' ')
    {
      stringCount++;
      continue;
    }

    inputs[stringCount] += input[i];
  }

  std::vector<std::string *> result = std::vector<std::string *>(stringCount + 1);

  for (int i = 0; i <= stringCount; i++)
  {
    result.at(i) = &inputs[i];
  }

  return result;
}

void sort(std::vector<std::string *> strings)
{
  for (int i = 0; i < strings.size(); i++)
  {
    std::string* key = strings[i];
    std::string keyValue = *key;
    int j = i;
    while (j > 0 && strings.at(j-1)->compare(*key) > 0)
    {
      strings.at(j) = strings.at(j - 1);
      j--;
    }
    strings.at(j) = key;
  }
}

int main()
{
  std::vector<std::string *> strings = readVector();

  sort(strings);

  for (int i = 0; i < strings.size(); i++)
  {
    std::string value = *strings[i];
    std::cout << value << std::endl;
  }

  return 0;
}