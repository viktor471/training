#include <iostream>

class A {

public:
     A() {  std::cout  <<  "default A constructor"  <<  std::endl; }
    ~A() {  std::cout  <<  "A destructor"           <<  std::endl; }
};


class B
{

public:
    A _ex_1;
    A _ex_2;

     B() { std::cout << "B constructor" << std::endl; }
    ~B() { std::cout << "B destructor"  << std::endl; }

};

class D
{
public:
    int a;
    int *b;
      D() { a = 4; b = new int(3); std::cout << "D constructor" << std::endl; }
     ~D() { delete b; std::cout << "D destructor " << std::endl; }
};

class C
{

public:
    A _ex_1;
    D _ex_2;

     C() : _ex_1( A( A( A() ) ) )
     {
         _ex_2 = D();
         std::cout << "B constructor" << std::endl;
     }

    ~C() { std::cout << "B destructor"  << std::endl; }

};

int main()
{
    int a = int();
    int b = int();
    int c = int();
    D _ex_2;
    std::cout << a << b << c << std::endl;
    C ex_1;
    return 0;
}
