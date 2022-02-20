#include <QCoreApplication>
#include <iostream>
#include <thread>
#include <mutex>

class Test
{
public:
    ~Test()
    {
        std::cout << "Test destructor" << std::endl;
    }
    int var = 33;
};

int main()
{
    Test a;
    a.~Test();
    std::cout << a.var << std::endl;
    return 0;
}
