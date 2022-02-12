#include <iostream>

class A
{
public:
    A()  { std::cout << "default constructor" << std::endl; }
    ~A() { std::cout << "destructor"          << std::endl; }
    A( const A&  another ) { std::cout << "copy constructor" << std::endl; }
    A(       A&& another ) { std::cout << "move constructor" << std::endl; }
    A& operator=( const A&  another ) { std::cout << "copy assignment" << std::endl; }
    A& operator=(       A&& another ) { std::cout << "move assignment" << std::endl; }

    const A& return_A() { return A(); }

};

int main()
{
    A ex_1;
    A ex_2 = ex_1.return_A();

    std::cout << "before reference return" << std::endl;
    const A& ex_3 = A();

    std::cout << "before return" << std::endl;
    return 0;
}
