#include <iostream>

void log( const std::string &msg )
{
    std::cout << msg << std::endl;
}


class A{
public:
    A()  { log( "default constructor" ); }
    ~A() { log( "destructor"          ); }


    A( const A& another ) { std::cout << "copy constructor" << std::endl; }
    A( A&& another      ) { std::cout << "move constructor" << std::endl; }

    A& operator=( const A& another ) { std::cout << "copy assignment" << std::endl; }
    A& operator=( A&&      another ) { std::cout << "move assignment" << std::endl; }
};

int main()
{
    log( "creation of ex_1" );
    A ex_1;
    log( "end of creation of ex_1" );


    return 0;
}
