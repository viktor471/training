#include <iostream>

class A
{
public:
    bool constexpr_or_not = false;
    constexpr A(int a) { constexpr_or_not = true; }
    A() { std::cout << "i'm not constexpr" << std::endl; }
};

int main()
{
    const int c = 0;
    constexpr A a(c);

    return 0;
}
