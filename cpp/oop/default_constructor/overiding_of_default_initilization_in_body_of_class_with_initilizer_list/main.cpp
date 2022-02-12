#include <iostream>

class A
{
public:
    int a = 3, b = 4, c = 5, d = 6;
    A( int a = 0, int b = 1, int c = 2 ) : a(a), b(b), c(c) {
        std::cout << "default constructor" << std::endl;
    }

};

class B
{
public:
    int a = 3, b = 4, c = 5, d = 6;
    B() { std::cout << "def constructor B" << std::endl; }
};

int main()
{
    A ex_1;
    std::cout   << ex_1.a << " " << ex_1.b << " " << ex_1.c << " "
                << ex_1.d << std::endl;

    A ex_2{1,2,3};

    std::cout   << ex_2.a << " " << ex_2.b << " " << ex_2.c << " "
                << ex_2.d << std::endl;

    B ex_3;
    return 0;
}
