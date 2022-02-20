#include <iostream>
#include <functional>

using namespace std;

std::function< void(void) > return_function( int number )
{
         if( number == 0 )
            return [](){ std::cout << "number 0" << std::endl;              };
    else if( number == 1 )
            return [](){ std::cout << "number 1" << std::endl;              };
    else
            return [](){ std::cout << "unrecognizable number" << std::endl; };

}

int main()
{
    auto func { return_function(1) };
    func();
    std::function<void(void) > func2{ return_function(2) };
    func2();
    func2 = return_function(0);
    func2();

    return 0;
}
