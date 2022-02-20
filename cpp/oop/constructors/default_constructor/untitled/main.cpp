#include <iostream>

class A
{
public:
    int a, b, c, d, e, f, g, i, k;
};

class B
{
public:
    B() = default;
    int a, b, c, d, e, f, g, i, k;
};

int main()
{
    A ex_1{ 1, 2, 3 };

    std::cout   << ex_1.a << " " << ex_1.b << " " << ex_1.c << " "
                << ex_1.d << " " << ex_1.e << " " << ex_1.f << " "
                << ex_1.g << " " << ex_1.i << " " << ex_1.k << " "
                << std::endl;

    A ex_2 = { 1, 2, 3 };

    std::cout   << ex_2.a << " " << ex_2.b << " " << ex_2.c << " "
                << ex_2.d << " " << ex_2.e << " " << ex_2.f << " "
                << ex_2.g << " " << ex_2.i << " " << ex_2.k << " "
                << std::endl;

    B ex_3 = { 1, 2, 3 };

    std::cout   << ex_3.a << " " << ex_3.b << " " << ex_3.c << " "
                << ex_3.d << " " << ex_3.e << " " << ex_3.f << " "
                << ex_3.g << " " << ex_3.i << " " << ex_3.k << " "
                << std::endl;

    return 0;
}
