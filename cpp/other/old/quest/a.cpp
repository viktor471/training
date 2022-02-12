#include <iostream>

using namespace std;

int main()
{

	int a, b;
	cout << "Enter your 1st number" << endl;
	cin >> a;
	cout << "Enter your 2nd number" << endl;
	cin >> b;
	cout << "Your values:" << endl;
	cout << "a: " << a <<  " b: " << b << endl;

	cout << "a = a + b  = " << a << " + " << b << endl;
	a = a + b;
	cout << "a: " << a << endl << endl;
	
	cout << "b = a - b = " << a << " - " << b << endl;
	b = a - b;
	cout << "b: " << b << endl << endl;

	cout << "a = a - b = " << a << " - " << b << endl;
	a = a - b;
	cout << "a: " << a << endl << endl;

	cout << "b: " << b << " a: " << a << endl;
}
