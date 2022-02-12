#include <iostream>

class A
{
public:
    int a = 3;
    int b{4};
    int c = int(6);
    int d[4] = {9,9,9,9};
    int e[4]{8,8,8,8};
};

class B{
public:
    int a = 3;
    int b{4};
    int c;
    int d[4] = {9,9,9,9};
    int e[4]{8,8,8,8};
    int f;
    int g;
    int i;
    int k;

    B() = default;
};

class D{
public:
    int a;
    int b;
    int c;
    int d[4];
    int e[4];

    D() = default;
};

int main()
{
    A ex;
    std::cout << "ex.a: "  << ex.a    << std::endl;
    std::cout << "ex.b: "  << ex.b    << std::endl;
    std::cout << "ex.c: "  << ex.c    << std::endl;

    for( uint32_t i = 0; i < sizeof( ex.d ) / sizeof(int); i++ )
        std::cout << "ex.d[" << i << "]: " << ex.d[i] << std::endl;

    for( uint32_t i = 0; i < sizeof( ex.d ) / sizeof(int); i++ )
        std::cout << "ex.e[" << i << "]: " << ex.e[i] << std::endl;

    B ex2 = B();

    std::cout << "ex2.a " << ex2.a << std::endl;
    std::cout << "ex2.c " << ex2.c << std::endl;
    std::cout << "ex2.b " << ex2.b << std::endl;
    std::cout << "ex2.i " << ex2.i << std::endl;
    std::cout << "ex2.k " << ex2.k << std::endl;
    std::cout << "ex2.f " << ex2.f << std::endl;
    std::cout << "ex2.g " << ex2.g << std::endl;

    for( uint32_t i = 0; i < sizeof( ex2.d ) / sizeof(int); i++ )
        std::cout << "ex2.e[" << i << "]: " << ex2.e[i] << std::endl;

    D ex3 = D();

    std::cout << "ex3.a: " << ex3.a << std::endl;
    std::cout << "ex3.b: " << ex3.b << std::endl;
    std::cout << "ex3.c: " << ex3.c << std::endl;
    for( uint32_t i = 0; i < sizeof(ex3.d)/sizeof(int); i++ )
        std::cout << "ex3.d[" << i << "]: " << ex3.d[i] << std::endl;


    return 0;
}
