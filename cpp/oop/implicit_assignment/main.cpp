#include <iostream>


struct A
{
    int _a;

    explicit A( int var_ ) : _a( var_ )
    {
        std::cout << "explicit" << std::endl;
    }

    A( int &var_ ) : _a( var_ )
    {
        std::cout << "implicit" << std::endl;
    }

};

int main()
{
    A var = 4;
    return 0;
}
