#include <iostream>

int func( int var ){
  return ( var > 2 ) ? var : var < 1 ? 0 : 2;
}

constexpr int func_2( int var)
{
  return ( var > 2 ) ? var : var < 1 ? 0 : 2;
}

const int     var_1 = func(2);
//constexpr in global_var_2 = func(2); // do not work
constexpr int var_2 = func_2(2);
constexpr int var_3 = 55;         // work

const int     var_4 = func_2(3);

//constexpr int from_const = global_var_1; // do not work
constexpr int from_const = var_4; // do not work

int main()
{
  const     int local_var_1 = func(2);
//  constexpr int local_var_2 = func(2); // do not work

  std::cout << " local_var_1:  " << local_var_1  << std::endl
            << " global_var_1: " << var_1 << std::endl
            << " gloval_var_2: " << var_2 << std::endl;
  return 0;
}
