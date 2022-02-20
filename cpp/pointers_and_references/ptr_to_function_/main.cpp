#include <iostream>

typedef void (*func_ptr)(void);

using namespace std;

void func(){ std::cout << "hello" << std::endl; }

int main()
{
  std::cout << func                             << std::endl;
  std::cout << &func                            << std::endl;
  std::cout << reinterpret_cast<func_ptr>(func) << std::endl;
  std::cout << reinterpret_cast<void*>   (func) << std::endl;
    return 0;
}
