#include <iostream>
#include <string>

int parse(const std::string &s)
{
  std::string number = "";

  for (int i = 0; i < s.length(); i++)
  {
    if (s[i] == ' ')
      if (!number.empty())
        break;
      else
        continue;
    else if (s[i] < '0' || s[i] > '9')
    {
      number = "-1";
      break;
    }
    else
      number += s[i];
  }

  if(number.empty())
    return -1;

  return stoi(number);
}

int main()
{
  std::string input;
  std::cout << "Bitte machen Sie eine Eingabe: " << std::endl;
  std::getline(std::cin, input);

  int result = parse(input);

  if (result == -1)
  {
    std::cout << "Keine Zahl erkannt." << std::endl;
  }
  else
  {
    std::cout << "Erkannte Zahl: " << result << std::endl;
  }

  return 0;
}