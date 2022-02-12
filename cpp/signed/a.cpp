#include <iostream>
#include <iomanip>
#include <cstdint>

using namespace std;

enum sign{ UNSIGNED, SIGNED };

template <typename T>
void binary_view(T value)
{
	for(int i = static_cast<int>(sizeof(value))*8 - 1; i >= 0; --i)
	{
//		cout <<" i: " << i << endl;
		if(!((i + 1)%4)) cout << " ";
		if(!((i + 1)%8)) cout << " ";
		cout << ((value & ( 1 << i)) && 1);
	}
	cout <<  " " << value << endl << endl;
}

template <typename T>
unsigned int  getMaxSizeOfInt(T value, sign  s = UNSIGNED )
{
	T val = 0;
	val= ~val;
	if(s) val ^= (1 << static_cast<T>(sizeof(T))*8 - 1);
	return static_cast<unsigned int>(val);
}
int pow(int base, int degree)
{
	int buf = base;
	while(--degree)
		base*=buf;
	return base;
}

int main ()                                   
{                                             
	short signed int b;                           
	cout << "sizeof (b) " << sizeof (b) << endl;
	                       
	b = 0xFFFF;
	cout << "b = 0xFFFF" << endl;

	for(int i = 0 ; i <  getMaxSizeOfInt(b); i++) 
		binary_view(b--);

}
