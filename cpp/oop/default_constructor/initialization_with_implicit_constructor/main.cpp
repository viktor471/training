#include <iostream>

using namespace std;

class A
{
public:
    int a;
    int b;
    int c;
};

class B
{
public:
    int a;
    int b;
    int c;
    B() = default;
};

class C
{
public:
    int a{2};
    int b = {3};
    int c = 4;
    C() = default;
};


int main()
{
    //--------------------
//  A a(1,2,3);
    //---------------------
    A a{1,2,3};

    std::cout << a.a << " " << a.b << " " << a.c << std::endl;

    //---------------------
    A b = {1, 3, 4};

    std::cout << b.a << " " << b.b << " " << b.c << std::endl;

    //---------------------

//  B c(22,33,44);

    //---------------------

//   B c = B(22,33,44);

    //---------------------
    B c{};

    std::cout << "c.a: " << c.a << " c.b: " << c.b << " c.c: " << c.c << std::endl;

    //---------------------
    C d{};

    std::cout << "d.a: " << d.a << " d.b: " << d.b << " d.c: " << d.c << std::endl;

    return 0;
}
