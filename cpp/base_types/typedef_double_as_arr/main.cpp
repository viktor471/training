#include <iostream>

using namespace std;
typedef double delay_polynomial_t[3];
int main()
{
  delay_polynomial_t a;

  std::cout << "sizeof( a ):      " << sizeof( a )      << std::endl;
  std::cout << "sizeof( double ): " << sizeof( double ) << std::endl;
  std::cout << "sizeof( a[0] ):   " << sizeof( a[0]   ) << std::endl;
  return 0;
}
