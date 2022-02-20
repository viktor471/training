#include <iostream>

using namespace std;

class cl{

    int n = 5;
public:
    void print() {
        cout << n << endl;
    }

    void print() const{
        cout  << n << endl;
    }

    /*int &ref(){
        return n;
    }*/

    int &ref() {
        return n;
    }
    const int &ref() const {
        return n;
    }

    int noRef() {
        return n;
    }

    int noRef() const{
        return n;
    }

};

int main()
{
    const cl ex;
    ex.print();
    int var1 = ex.ref();
    var1 = 7;
    ex.print();
    int var2 = ex.noRef();

    cl ex2;

    int &us_ref = ex2.ref();
    us_ref = 66;
    ex2.print();

    //int &us_ref2 = ex2.noRef();

}
