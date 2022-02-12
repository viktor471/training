#include <iostream>

using namespace std;

void func()
{
    cout << "hello" << endl;
}

int var1;

int main()
{
    ::func();
    return 0;
}
