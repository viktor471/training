#include <iostream>


void print_int( int number_for_print )
{
  std::cout << number_for_print << std::endl;

}

void print_int2( int number_for_print )
{
  std::cout << number_for_print << std::endl;

}

int main()
{

  int var;

  int *var2 = ( &( *(new int(99)) = 3 ) );

  int *var3 = var2;

  int &var4 = *var2;

  std::cout << var4 << std::endl;

  std::cout << "print_int " << reinterpret_cast< void * > ( &print_int2 ) << std::endl;
  std::cout << "print_int " << reinterpret_cast< void * > ( &print_int ) << std::endl;

}
