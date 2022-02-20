#include <iostream>

using namespace std;

class a
{
public:
    int b;
    a(){ cout << "constructor" << endl; }
    ~a(){ cout << "destructor" << endl; }
};

int main()
{
    cout << "a h();" << endl;
    a h();
    //cout << h.b << endl;
    cout << endl << "a h2{};" << endl;
    a h2{};
    cout << endl << "a h3 = a()" << endl;
    a h3 = a();
    cout << endl << "a h4 = a{}" << endl;
    a h4 = a{};
    cout << endl << "Hello World!" << endl;
    //h2();
    //h2{};
    int a;
    //a(3);
    //a{4};
    return 0;
}
