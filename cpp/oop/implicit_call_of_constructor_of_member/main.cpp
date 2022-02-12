#include <iostream>

class B
{
public:
     B() { std::cout << "B constructor" << std::endl; }
    ~B() { std::cout << "B destructor"  << std::endl; }
};

class A
{
public:
    B _ex_1;
     A() { std::cout << "A constructor" << std::endl; }
    ~A() { std::cout << "A destructor"  << std::endl; }
};

int main()
{
    A ex_1;
    return 0;
}
