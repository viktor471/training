#include <QCoreApplication>
#include <thread>
#include <iostream>

class Test
{
public:
    int a;
    void func()
    {
        std::cout << "hello" << std::endl;
    }
    Test(){
        std::thread th( [this](int b )
        {
            func();
            a = 99;
            std::cout << "b: " << b << std::endl;
        }
        , 349

        );
        th.join();
    }
};

int main()
{
    Test test;
    std::cout << "a: " << test.a << std::endl;
    return 0;
}
