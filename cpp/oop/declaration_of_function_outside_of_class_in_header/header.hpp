#include <iostream>

class A
{
public:
   A() = default;
	void func();
};

void A::func() { std::cout << "hello" << std::endl; }

