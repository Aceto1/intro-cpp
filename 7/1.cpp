#include <iostream>

using namespace std;

class Time
{
  // Daten
private:
  int minuten;
  // Methoden
public:
  virtual void set(int h, int m) {
    minuten = h * 60 + m;
  };

  virtual void get(int &h, int &m) const {
    h = minuten / 60;
    m = minuten % 60;
  };

  virtual void inc() {
    minuten++;
  };

  Time()
  {
    minuten = 0;
    cout << "Standard-Konstruktor" << endl;
  };
  
  Time(int m)
  {
    minuten = m;
    cout << "Minuten-Konstruktor" << endl;
  };

  Time(int h, int m)
  {
    minuten = h * 60 + m;
    cout << "Minuten & Stunden-Konstruktor" << endl;
  };

  Time(const Time &other)
  {
    minuten = other.minuten;
    cout << "Kopier-Konstruktor" << endl;
  };

  virtual ~Time() {
    cout << "Destruktor" << endl;
  };
};

void print(Time t)
{
  int h, m;
  t.get(h, m);  
  cout << h << ":" << m << endl;
}

Time input()
{
  Time result;
  int h, m;
  cout << "Uhrzeit eingeben - Stunde: ";
  cin >> h;
  cout << "                   Minute: ";
  cin >> m;
  result.set(h, m);
  return result;
}

int main(int argc, char *argv[])
{
  Time t1(10, 10);
  Time t2;
  t2 = input();
  t2.inc();
  print(t2);
  print(1234);
  return 0;
}