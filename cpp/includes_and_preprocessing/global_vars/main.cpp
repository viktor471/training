#include <QCoreApplication>
#include <iostream>
#include "global_vars.hpp"
#include "func_1.hpp"
#include "func_2.hpp"

int main()
{
  func_1();
  func_2();
  std::cout << i << std::endl;
  return 0;
}
