#include <iostream>
#include <string>

void print( const std::string &msg )
{
	std::cout << msg << std::endl;
}

class A 
{
	public:
		explicit A(int a, int b) { print("explicit"); }
		A(char a, char b)        { print("implicit"); }

};


int main()
{
	A(2,3);
	long a = 77, b = 88;
	A(a,b);
}
