#include <QCoreApplication>
#include <thread>
#include <iostream>



void func( std::reference_wrapper<int> _ref )
{
   std::cout << _ref.get() << std::endl;
   _ref++;
   std::cout << _ref.get() << std::endl;
   _ref.get()--;
   std::cout << _ref << std::endl;
   _ref--;
}

void func2( int& var )
{
   std::cout << var << std::endl;
}

int main()
{
    int var = 3;

    std::list< std::thread > list;
    list.push_back( std::thread( func2, std::ref(var) ) );
    list.push_back( std::thread( func, std::ref(var) ) );
//    list.push_back( std::thread( func, var ) );

    for( std::thread &th : list )
        th.join();

    std::cout << "main: " << var << std::endl;

    return 0;
}
