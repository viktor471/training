#include <iostream>


class A
{
public:
    int a = 2, b = 4, c, d;

};

class B
{
public:
    int a = 2, b = 4, c, d;
    B(){};
};

int main()
{
    A a;
    char c = ' ';
    std::cout << a.a << c << a.b << c << a.c << c << a.d << std::endl;

    A b = A();

    std::cout << b.a << " " << b.b << " " << b.c << " " << b.d << std::endl;

    B d;

    std::cout << d.a << " " << d.b << " " << d.c << " " << d.d << std::endl;

    B e = B();

    std::cout << e.a << " " << e.b << " " << e.c << " " << e.d << std::endl;

    return 0;
}
