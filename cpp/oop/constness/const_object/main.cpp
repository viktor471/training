#include <iostream>

using namespace std;
class a
{
public:
    static int b;
    int c;
    const int d;
    static const int e;
    const string type;
    a() : d{4}, c(5) { }
    //a() { d = 5; b =0; }
    a(string str) : type(str), d(4){};
    void changeB(int val) const {b = val;}
    void changeC(int val) {c = val;}
    //void changeC(int val) const {c = val;}
    //void changeD(int val) {d = val;}
    //void changeE(int val) {e = val;}
    //void cnangeE(int val) const {e = val;}
    void nonConstWithouChanges()
    {
        cout << "non-const function without changing anything in class" << endl;
        cout << "current type of class: " << type << endl << endl;
    }

    void constWithoutChanges() const
    {
        cout << "const function without changing anything in class" << endl;
        cout << "current type of class: " << type << endl << endl;
    }

};

int main()
{
    a h("non-const");
    //cout << "h.b: " << h.b << endl;
    //cout << "h:b" << a::b << endl;
    cout << "h.c: " << h.c << " h.d: " << h.d << endl;
    cout << "Hello World!" << endl;
    h.constWithoutChanges();
    h.constWithoutChanges();

    const a h2("const");

    //h2.nonConstWithouChanges();
    h2.constWithoutChanges();
    //h2.changeC(3);
    //h2.c = 3;
    const a h3 = a("const");
    const a h4;
    //h4 = a("const");
    const a h5{};
    const a h6 = a();
    //const a h7 = (a().c = 4);
    return 0;
}
