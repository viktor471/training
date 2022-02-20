#include <iostream>
#include <string>

void print( const std::string& msg )
{
	std::cout << msg << std::endl;
}

class A
{
public:
	int _a, _b;
	A( int    a, int    b ) { print( "int a, int b"       ); }	
	A( char   a, char   b ) { print( "char a, char b"     ); }	
	A( double a, double b ) { print( "double a, double b" ); }	
};


int main()
{
	A( static_cast<int>(3), static_cast<int>(4) );
	A( static_cast<char>(3), static_cast<char>(4) );
	A( 3, 4 );
}
