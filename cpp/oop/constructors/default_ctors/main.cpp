#include <iostream>
#include <cstring>

class A{
public:
    A() = default;
    //A(A& a) = default;
    int a, b;
};

class B{
public:
    int a, b;
};

class C{
public:
    C() = default;
    C(C & a) = default;
    int a, b;
    void show(){
        std::cout << a << " " << b << std::endl;
    }
};

class D{
public:
//    D(){}
   void show(){
        std::cout << a << " " << b << std::endl;
   }

   int a, b;
};

class E{
public:
   E(){}
   void show(){
        std::cout << a << " " << b << std::endl;
   }

   int a, b;
};

class F{
public:
   F(){}
   int a, b;
};

int main()
{
    A a;
    a.a = 3;
    a.b = 55;

    A b;
    b = a;
    B c;
    C d;
    D e;
    D f{0,0};
    memcpy( &c, &b, sizeof(B) );
    memcpy( &d, &c, sizeof(C) );
    d.show();
//    d = a;
    e.show();
    D k = {};
    E g = {};
    F i = {};

    std::cout << "k.a " << k.a << " k.b " << k.b << std::endl;

    std::cout << "g.a " << g.a << " g.b " << g.b << std::endl;

    std::cout << "f.a " << f.a << " f.b " << f.b << std::endl;

    //std::cout << b.a << " " << b.b << std::endl;
    return 0;
}
