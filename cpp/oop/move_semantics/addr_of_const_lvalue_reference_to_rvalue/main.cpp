#include <iostream>

using namespace std;


int main()
{
  const int &lvalue_ref_1 = 10;
  std::cout << &lvalue_ref_1 << std::endl;

  const int &lvalue_ref_2 = 10;
  std::cout << &lvalue_ref_2 << std::endl;

  const int const_lvalue = 10;
  const int &lvalue_ref_3 = const_lvalue;
  std::cout << &lvalue_ref_3 << std::endl;
  return 0;
}
