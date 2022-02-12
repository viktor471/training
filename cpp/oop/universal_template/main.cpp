#include <iostream>
#include <string>
#include <iomanip>


void log( const std::string &msg ) { std::cout << msg << std::endl; }

template <typename T>
void log( const std::string &msg, const T& var )
{
    using namespace std;
    cout << setw(15) << left << msg << ": " << var << endl;
}

class Test
{
    int _member;
public:

    int get_member() { return _member; }
    Test() :
        _member( 0 )
    {
        log( "default ctor" );
    }

    Test( int value ) : _member(value) {};

    Test( const Test &ex ) :
        _member( ex._member )
    {
        log( "copy ctor"    );
    }

    Test( Test &&ex      ) :
        _member( ex._member )
    {
        log( "move ctor"    ); ex._member = 0;
    }

    Test& operator=( const Test &ex  )
    {
        log( "copy assignment" );
        _member = ex._member;
        return *this;
    }

    Test& operator=( Test &&ex )
    {
        log( "copy assignment" );
        _member = ex._member;
        ex._member = 0;
        return *this;
    }

    Test operator-()
    {
        return Test(-_member);
    }

    friend std::ostream& operator<<( std::ostream &out, const Test& ex )
    {
        out << ex._member;
        return out;
    }
};

//template <typename T>
//T& negat( T& ex )  { return ex = -ex; }

template <typename T>
T& negat( T&& ex ) { return ex = -ex; }

int main()
{
    int int_a = 99;
    Test test(33);

    log( "(-test).get_member()", (-test).get_member() );

    log( "negat(Test(88))", negat(Test(88))    );
    log( "negat(test)",     negat(test)        );
    log( "test",            test               );

    log( "negat(3)",     negat( 3 )     );
    log( "negat(int_a)", negat( int_a ) );

    return 0;
}
