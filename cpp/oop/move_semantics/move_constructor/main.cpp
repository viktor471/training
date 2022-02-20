#include <iostream>

class A
{
public:
    int _a;
    A( A&& var_ ) : _a( var_._a )
    {
        std::cout << "move constructor" << std::endl;
    }

    A( int& var_ ) : _a( var_ )
    {
        std::cout << "copy constructor" << std::endl;
    }

    A( A& a ) : _a( a._a )
    {
        std::cout << "copy constructor" << std::endl;
    }


    A( int var_ ) : _a( var_ )
    {
        std::cout << "common constructor" << std::endl;
    }

//    A& operator=( A&& a ) = default;

    A&& operator=( A&& a )
    {
        std::cout << "move operator" << std::endl;
        return std::move(a);
    }

};

int main()
{

    A ex_0(3);
    A ex_1( std::move(ex_0) );
    A ex_2( ex_0 );
    A ex_3 = ex_2;
    ex_0 = std::move(ex_1);
    return 0;
}
