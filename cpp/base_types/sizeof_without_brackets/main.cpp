#include <iostream>

void func() {}
class A
{

};

int main()
{

  std::cout << sizeof 5   << std::endl;
  std::cout << sizeof 6.0 << std::endl;
  std::cout << sizeof 'a' << std::endl;
  std::cout << sizeof "hello" << std::endl;
  std::cout << sizeof(A) << std::endl;
  return 0;
}
