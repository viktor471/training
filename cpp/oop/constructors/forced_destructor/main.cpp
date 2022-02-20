#include <QCoreApplication>
#include <iostream>

class A
{
public:
    int a = 3;
    A()
    {
        std::cout << "constructor" << std::endl;
    }

    ~A()
    {
        std::cout << "destructor" << std::endl;
    }
};

int main()
{
    A a;
    a.~A();
    std::cout << "end" << std::endl;
    return 0;
}
