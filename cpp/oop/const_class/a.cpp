#include <iostream>
#include <cstring>
#include <bitset>

class A
{
public:
	int a = 8;
	A() { a = 9; }
	void set_a( int a ) { this->a = a; }
	int get_a() const  { return a;    }

};

int main()
{
	const A a;

	std::cout << a.a << std::endl;

//	a.a = 99;
//
//int bin_number = 0b10001;
	int oct_number = 010;
	int hex_number = 0xff;
	int bin_number = 0b0000'0001'0000'0001;
	
   memset( (char*)&a.a, 1, sizeof( short ) );

	std::cout << "a.a: " << a.a  << std::endl;
	std::cout << 0b11 << std::endl;
	std::cout << 010  << std::endl;
	std::cout << 0xff << std::endl;
	std::cout << "bin_number " << bin_number << std::endl;
	std::cout << std::bitset<8>(3) << std::endl;

	
	for ( int i = 0 ; i < 100; i++ )
		std::cout << std::bitset<8>(i) << " " << i << std::endl;





}
