#include <thread>
#include <iostream>
#include <QCoreApplication>
#include <list>

class Test
{
public:
    int a = 5;
    void method_1()
    {
        std::cout << 4 << std::endl;
    }

    void method_2( int b )
    {
        a++;
        std::cout << a << " " << b << std::endl;
    }
};

int main(int argc, char *argv[])
{
    std::list< std::thread > list;

    Test obj;
    list.push_back( std::thread( &Test::method_1, obj ) );
    list.push_back( std::thread( &Test::method_2, obj, 3 ) );

    for( std::thread &th : list)
        th.join();

    return 0;
}
