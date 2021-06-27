#include <vector>
#include <iostream>

using namespace std;

class IntMenge
{
private:
  int min;
  int max;
  vector<int> set;

public:
  IntMenge(int min, int max) : min(min), max(max)
  {
    set = vector<int>();
  };

  bool isValid(int i)
  {
    return min <= i && i <= max;
  };

  void add(int i)
  {
    for (int j = 0; j < set.size(); j++)
    {
      if (i == set.at(j))
        return;
    }

    set.push_back(i);
  };

  void remove(int i)
  {
    for (int j = 0; j < set.size(); j++)
    {
      if (i == set.at(j))
        set.erase(set.begin() + j);
    }
  };

  bool contains(int i)
  {
    for (int j = 0; j < set.size(); j++)
    {
      if (i == set.at(j))
        return true;
    }
  };

  bool isEmpty()
  {
    return set.size() == 0;
  };

  int getSize()
  {
    return set.size();
  };

  vector<int> getElements()
  {
    return set;
  };

  void print()
  {
    for (int j = 0; j < set.size(); j++)
    {
      cout << set.at(j) << endl;
    }
  };
};

int main()
{
  IntMenge m(10, 100);
  int input;
  cin >> input;

  while (input != 0)
  {
    if (m.isValid(input))
      m.add(input);
    cout << "Menge enthält " << m.getSize() << " Elemente:" << endl;
    m.print();
    cin >> input;
  }

  vector<int> intv = m.getElements();
  for (int i = 0; i < intv.size(); i++)
    m.remove(intv[i]);

  cout << (m.isEmpty() ? "Menge ist leer" : "Menge ist nicht leer") << endl;
}