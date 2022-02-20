#include <iostream>

class A
{
  public:
  int _i;

  A( int i = 0 ) :
    _i(i)
  {
    std::cout << "constructor"
              << std::endl;
  }

  int& getter()
  {
    std::cout << "in class &_i: "
              << &_i
              << std::endl;
    return _i;
  }

  ~A()
  {
    std::cout << "destructor"
              << std::endl;
  }

};

A& func()
{
  A a;
  return a;
}

int main()
{
  //A a = func();
  A ex(33);

  int &i = ex.getter();

  std::cout << "in main &i: "
            << &i
            << std::endl;
  return 0;
}
