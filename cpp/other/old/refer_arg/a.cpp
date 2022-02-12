#include <iostream>

using namespace std;

void func( const int &a)
{
	cout << "a: " << a << endl;
}

int main()
{
   func(3);	
}
