#include <iostream>

template <typename T>
class Interval
{
private:
  T upperBound;
  T lowerBound;
  bool valid;

public:
  Interval() : valid(false){};
  Interval(T bound1, T bound2) : valid(true)
  {
    upperBound = bound1 <= bound2 ? bound2 : bound1;
    lowerBound = bound1 <= bound2 ? bound1 : bound2;
  };
  Interval(T bound) : upperBound(bound), lowerBound(bound), valid(true){};
  void get(T *lowerBound, T *upperBound)
  {
    &lowerBound = this->lowerBound;
    &upperBound = this->upperBound;
  };
  void set(const T bound1, const T bound2)
  {
    upperBound = bound1 <= bound2 ? bound2 : bound1;
    lowerBound = bound1 <= bound2 ? bound1 : bound2;
    valid = true;
  };
  bool isValid()
  {
    return valid;
  };
  void print()
  {
    if (valid)
      std::cout << "[" << lowerBound << "," << upperBound << "]" << std::endl;
    else
      std::cout << "Intervall ist ungültig" << std::endl;
  };
  Interval<T> &operator+(const Interval<T> &other)
  {
    if (other.valid)
    {
      this->lowerBound += other.lowerBound;
      this->upperBound += other.upperBound;
    }
    else
      this->valid = false;

    return *this;
  }
  Interval<T> &operator-(const Interval<T> &other)
  {
    if (other.valid)
    {
      this->lowerBound -= other.lowerBound;
      this->upperBound -= other.upperBound;
    }
    else
      this->valid = false;

    return *this;
  }
  Interval<T> &operator-()
  {
    if (this->valid)
    {
      this->lowerBound = -this->lowerBound;
      this->upperBound = -this->upperBound;
    }

    return *this;
  }
  Interval<T> &operator*(const Interval<T> &other)
  {
    if (other.valid)
    {
      this->lowerBound *= other.lowerBound;
      this->upperBound *= other.upperBound;
    }
    else
      this->valid = false;

    return *this;
  }
  Interval<T> &operator/(const Interval<T> &other)
  {
    if (other.valid && other.lowerBound != 0 && other.upperBound != 0)
    {
      this->lowerBound /= other.lowerBound;
      this->upperBound /= other.upperBound;
    }
    else
      this->valid = false;

    return *this;
  }
};

int main(int argc, char *argv[])
{
  Interval<int> i, j, k, l;

  i.print();
  i.set(3, 5);
  i.print();
  i.set(16, 4);
  i.print();

  j.set(2, 2);
  k.set(1, 3);
  j.print();
  k.print();

  i = i + j;
  i.print();

  i = i / j;
  i.print();

  i = i - k;
  i.print();

  j = j * k;
  j.print();

  i = i + l;
  i.print();

  l.set(0, 2);
  j = j / l;
  j.print();

  return 1;
}