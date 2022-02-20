#include <iostream>

using namespace std;

int main()
{
    int value, degree;
    cout << "enter your value: ";
    cin >> value;
    cout << "enter your degree: ";
    cin >> degree;
    cout << "value: " << value << "degree: " << degree << endl;
    cout << "degree>>=1 " << (degree>>=1) << endl;
    return 0;
}
