#include <iostream>

class A
{
public:
  A( const A& a )
  {
    std::cout << "copy_constructor" << std::endl;
  }
  A()
  {
    std::cout << "common_constructor" << std::endl;
  }
  A( A&& a )
  {
    std::cout << "move constructor" << std::endl;
  }
  A& operator=( A& )
  {
    std::cout << "copy assignment" << std::endl;
  }
  A& operator=( A&& )
  {
    std::cout << "move assignment" << std::endl;
  }

};

int main()
{
  A a = A();
  A b;
  A c = b;
  c = b;
  c = std::move(b);
  return 0;
}
