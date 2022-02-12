#include <iostream>
#include <functional>

using namespace std;

template < typename T >
void func( T variable )
{
    static int counter = 0;
    std::cout << "func"      << std::endl;
    std::cout << "counter: " << counter++ << " "
              << "var: "     << variable  << std::endl;
}

auto func2{
    []( auto variable )
    {
        static int counter = 0;
        std::cout  << "func2"     << std::endl;
        std::cout  << "counter: " << counter++ << " "
                   << "var: "     << variable  << std::endl;
    }
};

template < typename T >
void (*func3)(T variable) =
[]( T variable )
{
    static int counter = 0;
    std::cout << "func3"     << std::endl;
    std::cout << "counter: " << counter++ << " "
              << "var:     " << variable  << std::endl;
};

int main()
{
    func( 2.3     );
    func( 4       );
    func( "hello" );
    func( "world" );

    std::cout << " " << std::endl;

    func2( 2.3     );
    func2( 4       );
    func2( "hello" );
    func2( "world" );

    std::cout << " " << std::endl;

    func3< float       >( 2.3     );
    func3< int         >( 4       );
    func3< std::string >( "hello" );
    func3< std::string >( "world" );

    return 0;
}
