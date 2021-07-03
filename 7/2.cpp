#include <vector>
#include <iostream>

using namespace std;

class IntMenge
{
private:
  int min;
  int max;
  vector<bool> set;

public:
  IntMenge(int min, int max) : min(min), max(max)
  {
    set = vector<bool>(max-min + 1);
    for (int i = 0; i < set.size(); i++)
    {
      set.at(i) = false;
    }
    
  };

  bool isValid(int i)
  {
    return min <= i && i <= max;
  };

  void add(int i)
  {
    set.at(i - min) = true;
  };

  void remove(int i)
  {
    set.at(i - min) = false;
  };

  bool contains(int i)
  {    
    return set.at(i - min);
  };

  bool isEmpty()
  {
    for (int i = 0; i < set.size(); i++)
    {
      if(set.at(i))
        return false;
    }
    
    return true;
  };

  int getSize()
  {
    int size = 0;
    for (int i = 0; i < set.size(); i++)
    {
      if(set.at(i))
        size++;
    }
    
    return size;
  };

  vector<int> getElements()
  {
    vector<int> result;
    for (int i = 0; i < set.size(); i++)
    {
      if(set.at(i))
        result.push_back(i + min);
    }

    return result;    
  };

  void print()
  {
    for (int i = 0; i < set.size(); i++)
    {
      if(set.at(i))
        cout << i + min << endl;
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