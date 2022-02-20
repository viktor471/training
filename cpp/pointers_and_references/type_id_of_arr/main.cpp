#include <iostream>

using namespace std;

int main()
{
    char arr[10];
    char *arr2;
    cout << typeid (arr).name() << endl;
    cout << typeid (arr2).name() << endl;
}
