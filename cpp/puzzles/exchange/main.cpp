#include <iostream>

using namespace std;

int main()
{
    int a, b;
    cout << "Please enter first value: " ;
    cin >> a;
    cout << "Please enter second value: ";
    cin >> b;
    cout << " a: " << a << " b: " << b << endl;
    cout << "exchange ..." << endl;
    a = a + b;
    b = a - b;
    a = a - b;
    cout << " a: " << a << " b: " << b << endl;
    cout << "Hello World!" << endl;
    return 0;
}
