#include <iostream>

class A
{

public:

    int a,b,c,d;

    A( const A& another )
    {
        std::cout << "copy constructor" << std::endl;
    }

    A(int a = 3, int b = 4)
    {
        std::cout << "default constructor" << std::endl;
    }

    A() = default;

    A( A&& another )
    {
        std::cout << "move constructor" << std::endl;
        std::cout << &another << std::endl;
    }

    A& operator=( A&& another )
    {
        std::cout << "assignment with move" << std::endl;
        return another;
    }

    A& operator=( A& another )
    {
        std::cout << "assignment with copy" << std::endl;
        return another;
    }

    ~A()
    {
        std::cout << "destructor" << std::endl;
    }
};


int main()
{
//    A ex_1;

//    std::cout << "&ex_1: " << &ex_1 << std::endl;

//    A ex_2( std::move(ex_1) );

//    A ex_3 = ex_1;

A ex_1 = A();

std::cout << ex_1.a << " " << ex_1.b << std::endl;
A ex_2 = {3,3};
//A ex_3 = {3,4,5};

    return 0;
}
