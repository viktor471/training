#include <iostream>

using namespace std;

class cl{
    int a[50];
    cl(){ cout << "constructor" << endl;}
    void func(){
        cout << "func" << endl;
    }
};

struct st{
    int a[50];
};

int main(int argc, char *argv[])
{
    cout << "sizeof class  " << sizeof ( cl ) << endl;
    cout << "sizeof struct " << sizeof ( st ) << endl;
return 3;
}
