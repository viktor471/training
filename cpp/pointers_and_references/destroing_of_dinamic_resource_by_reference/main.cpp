#include <QCoreApplication>
#include <iostream>

class A
{
public:
   A() { std::cout << "constructor" << std::endl; }
  ~A() { std::cout << "destructor"  << std::endl; }
};

int main()
{
  A *var = new A;
  A &ref = *var;

  return 0;
}
