#include <iostream>

int main()
{
   int n = 555;
   int *ptr = &n;
   int *&ref = ptr;

   std::cout << *ref << std::endl;

   *ref = 888;

   std::cout << *ref << std::endl;
    return 0;
}
