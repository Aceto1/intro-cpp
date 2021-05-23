#include <iostream>
#include <vector>
#include <limits>
#include <cmath>
#include <string>

std::vector<double> readVector()
{
  std::cout << "Geben Sie die Zahlen eines Vektor getrennt durch Leerzeichen ein:" << std::endl;
  std::string input;
  std::cin.clear();
  std::cin.sync();
  std::getline(std::cin, input);

  std::string stringNumbers[input.length()];
  int numberCount = 0;

  for (int i = 0; i < input.length(); i++)
  {
    if (input[i] == ' ')
    {
      numberCount++;
      continue;
    }

    stringNumbers[numberCount] += input[i];
  }

  std::vector<double> result = std::vector<double>(numberCount + 1);

  for (int i = 0; i <= numberCount; i++)
  {
    result[i] = std::stod(stringNumbers[i].c_str());
  }

  return result;
}

double max(const std::vector<double> &v)
{
  double max = std::numeric_limits<double>::min();
  for (int i = 0; i < v.size(); i++)
  {
    if (v[i] > max)
      max = v[i];
  }

  return max;
}

bool allPositive(const std::vector<double> &v)
{
  bool result = true;
  for (int i = 0; i < v.size(); i++)
  {
    if (v[i] <= 0)
    {
      result = false;
      break;
    }
  }

  return result;
}

double product(const std::vector<double> &v1, const std::vector<double> &v2)
{
  if (v1.size() != v2.size())
  {
    std::cout << "Vektoren haben unterschiedlich viele Einträge." << std::endl;
    return NAN;
  }

  double sum = 0.0;
  for (int i = 0; i < v1.size(); i++)
  {
    sum += v1[i] * v2[i];
  }

  return sum;
}

std::vector<double> product(const std::vector<double> &v, double f)
{
  std::vector<double> result = std::vector<double>(v.size());

  for (int i = 0; i < v.size(); i++)
  {
    result[i] = v[i] * f;
  }

  return result;
}

double norm(const std::vector<double> &v)
{
  double sum = 0.0;
  for (int i = 0; i < v.size(); i++)
  {
    sum += v[i] * v[i];
  }

  return sqrt(sum);
}

void normalize(std::vector<double> &v)
{
  double normValue = norm(v);

  v = product(v, 1.0f/normValue);
}

int main()
{
  std::cout << "Was möchten sie ausführen?" << std::endl;
  std::cout << "1 Max" << std::endl;
  std::cout << "2 AllPositive" << std::endl;
  std::cout << "3 Skalarprodukt" << std::endl;
  std::cout << "4 Produkt" << std::endl;
  std::cout << "5 Norm" << std::endl;
  std::cout << "6 Normalize" << std::endl;

  int option;
  std::cin >> option;
  std::vector<double> x;
  std::vector<double> y;

  switch (option)
  {
  case 1:
  {
    x = readVector();
    std::cout << "Ergebnis: " << max(x) << std::endl;
  }
  break;
  case 2:
  {
    x = readVector();
    std::cout << (allPositive(x) ? "Alle Werte sind positiv" : "Nicht alle Werte sind positiv") << std::endl;
  }
  break;
  case 3:
  {
    x = readVector();
    y = readVector();
    std::cout << "Ergebnis: " << product(x, y) << std::endl;
  }
  break;
  case 4:
  {
    x = readVector();
    std::cout << "Geben Sie den Faktor ein:" << std::endl;
    double factor;
    std::cin >> factor;
    y = product(x, factor);
    std::cout << "Ergebnis: " << "(";
    for (int i = 0; i < y.size(); i++)
    {
      std::cout << y[i];
      if (i < y.size() - 1)
        std::cout << ", ";
    }
    std::cout << ")" << std::endl;
  }
  break;
  case 5:
  {
    x = readVector();
    double result = norm(x);

    std::cout << "Ergebnis: " << result << std::endl;
  }
  break;
  case 6:
  {
    x = readVector();
    normalize(x);
    std::cout << "Ergebnis: " << "(";
    for (int i = 0; i < x.size(); i++)
    {
      std::cout << x[i];
      if (i < x.size() - 1)
        std::cout << ", ";
    }
    std::cout << ")" << std::endl;
  }
  break;
  default:
    break;
  }

  return 0;
}