#include <iostream>

using namespace std;

class Base
{
  public:
  Base() {};
  virtual void func(){ std::cout << "base func"  << std::endl; }
  void func2()       { std::cout << "base func2" << std::endl; }
};

class Inherented : public Base
{
public:
  Inherented() : Base() {}
  void func()  { std::cout << "inherented func " << std::endl; }
  void func2() { std::cout << "inherented func2" << std::endl; }
};

int main()
{
  Base b_ex;
  Inherented i_ex;
  Base &i_ex_ref = i_ex;
  i_ex_ref.func();
  i_ex_ref.func2();
  cout << "Hello World!" << endl;
  return 0;
}
