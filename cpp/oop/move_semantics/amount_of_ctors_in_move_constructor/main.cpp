#include <iostream>

class A
{
public:
    A( const A&  another ) { std::cout << "copy constructor" << std::endl; }
    A(       A&& another ) { std::cout << "move constructor" << std::endl; }
    A( ) { std::cout << "default constructor" << std::endl; }

    A& operator=( const A&  another ) { std::cout << "copy assignment" << std::endl; }
    A& operator=(       A&& another ) { std::cout << "move assignment" << std::endl; }
    ~A() { std::cout << "destructor" << std::endl; }
};

int main()
{
    A ex_1;

    std::cout << std::endl;
    A ex_2( std::move(ex_1) );

    return 0;
}
