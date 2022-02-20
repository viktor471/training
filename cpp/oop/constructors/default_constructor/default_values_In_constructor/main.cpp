#include <iostream>

class A
{
public:
    int a,b,c,d,e,f,g,i,k;

    A( int a = 1,
       int b = 2,
       int c = 3,
       int d = 4,
       int e = 5,
       int f = 6,
       int g = 7,
       int i = 8,
       int k = 9 ) :
        a(a), b(b), c(c), d(d), e(e), f(f), g(g), i(i), k(k) {}
};

int main()
{
    A ex_1;
    std::cout   << ex_1.a << " " << ex_1.b << " " << ex_1.c << " "
                << ex_1.d << " " << ex_1.e << " " << ex_1.f << " "
                << ex_1.g << " " << ex_1.i << " " << ex_1.k << std::endl;

    A ex_2 = A();
    std::cout   << ex_2.a << " " << ex_2.b << " " << ex_2.c << " "
                << ex_2.d << " " << ex_2.e << " " << ex_2.f << " "
                << ex_2.g << " " << ex_2.i << " " << ex_2.k << std::endl;

    return 0;
}
