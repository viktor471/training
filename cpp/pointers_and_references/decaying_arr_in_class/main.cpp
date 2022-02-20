#include <iostream>
#include <typeinfo>

using namespace std;

class my_class{

public:

    int arr[3];
    int arr2[3][3];

    void func()
    {
        std::cout << "arr:  " << typeid ( arr  ).name() << std::endl;
        std::cout << "arr size " << sizeof ( arr ) << std::endl;
        std::cout << "arr2: " << typeid ( arr2 ).name() << std::endl;
    }

};

int main()
{
    my_class a;
    a.func();

    std::cout << "outside of function: " << std::endl;

    std::cout << "arr:  " << typeid ( a.arr  ).name() << std::endl;
    std::cout << "arr2: " << typeid ( a.arr2 ).name() << std::endl;

    return 0;
}
