#include <QCoreApplication>
#include <iostream>
#include <memory>

class Test
{
public:
    Test()
    {
        std::cout << "constructor" << std::endl;
    }

    ~Test()
    {
        std::cout << "destructor" << std::endl;
    }
};

int main()
{
    Test a;
    std::shared_ptr<Test> s_ptr(&a);
    return 0;
}
