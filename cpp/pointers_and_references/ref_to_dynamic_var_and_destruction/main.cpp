#include <QCoreApplication>
#include <iostream>

class Test{
public:
int _a, _b;

  Test(int a_ = 0, int b_ = 0 ) :
    _a(a_), _b(b_)
  {
    std::cout << "ctor" << std::endl;
  }
  ~Test()
  {
    std::cout << "dctor" << std::endl;
  }
};

int main()
{
  Test &ref = *( new Test(99, 88) );
  return 0;
}
