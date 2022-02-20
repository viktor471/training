#include <iostream>
#include <string>

void print( const std::string &msg )
{
	std::cout << msg << std::endl;
}

class A
{
public:
	int _member;
	operator int() { print("conv function"); return _member; }
};

int main(){

	A ex;

	(int)ex;
	static_cast<int>(ex);
	int b = ex;
}
