#include <iostream>

void rec_func()
{
	static unsigned long long size_of_stack = sizeof( unsigned long long );
	unsigned long long a;
	size_of_stack += sizeof( unsigned long long );
	std::cout << "size_of_stack: " << size_of_stack << std::endl;
	rec_func();
}

int main()
{
	rec_func();
}
