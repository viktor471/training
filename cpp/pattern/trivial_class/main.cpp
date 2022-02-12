#include <iostream>

class A{
public:

    int a;
    int b;
};

struct B{
    int a;
    int b;
};

int main()
{
    //A(2,3);
    A{2,3};
    //B(2,4);

    return 0;
}
