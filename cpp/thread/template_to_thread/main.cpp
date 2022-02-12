#include <QCoreApplication>
#include <iostream>
#include <thread>
#include <vector>
#include <list>

class Test
{
public:
    Test( int a = 0 ) : _a(a) {}
    int _a;

    friend std::ostream& operator<<( std::ostream& output, const Test& object );
};

std::ostream& operator<<( std::ostream& output, const Test &object )
{
    return output << object._a;
}

template <typename type>
void func( type var )
{
    std::cout << "var: " << var << std::endl;
}

int main()
{

    std::list< std::thread > list;

    func(3);
    func<Test>( Test(40));
    func( Test(40));
    list.push_back( std::thread( func<int>, 3 ));
    list.push_back( std::thread( func<Test>, Test(4) ));
    for( std::thread &th : list )
        th.join();

    return 0;
}
