#include <iostream>

int &func()
{
 return *(new int(99));
}

int main()
{

 int &ref_to_dynamic_var = func();
 
 std::cout << ref_to_dynamic_var << std::endl;

 delete &ref_to_dynamic_var;
}
