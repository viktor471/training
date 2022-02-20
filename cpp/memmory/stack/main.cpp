#include <iostream>

using namespace std;

void a()
{
    cout << "in a" << endl;
}

void b()
{
    cout << "call of a in b" << endl;
    a();
}

void c()
{
    cout << "call of b in c" << endl;
    b();
    cout << "cal of a in c" << endl;
    a();
}

void d()
{
    cout << "call of c in d" << endl;
    c();
    cout << "call of b in d" << endl;
    b();
    cout << "call of a in d" << endl;
    a();
}

int recursion(int n)
{
    if( n > 0) recursion(n - 1);
    return 0;
}

int main()
{
    d();
    recursion(6);
    //int numb{3.4};
    return 0;
}
