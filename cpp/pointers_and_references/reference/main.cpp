#include <iostream>

using namespace std;

void func(int &c)
{
  c = 66;
}

int &func2(int &c)
{
  return c;
}

int &func3(int &c){
	return c;
}

int main()
{
	int a = 4444;
	int &b = a;
	int &d = b;
	int c = 4;

	cout << b << endl;

	b = 555;

	cout << a << endl;

	cout << "&b " << &b << endl;

	cout << "&a " << &a << endl;

	func(a);

	cout << "a: " << a << endl;

	func2(a) = 90;

	cout << "a: " << a << endl;

	cout << "&func2(a): " << &(func2(a)) << endl;
	cout << "&a:        " << &a	     << endl;
	d = 88;
	cout << "a: " << a << std::endl;
	b = c;

	//cout << a <<
	//&func3(a);
	return 0;
}
