#include <QCoreApplication>
#include <thread>
#include <list>
#include <iostream>
#include <functional>

using func_ptr =  void (*)(int);

int main()
{
    int variable = 99;

    std::list< std::thread > list;

    func_ptr func_pointer = []( int var ) {
        std::cout << "func_pointer  var: " << var << std::endl;
    };

    std::function<void(int)> func_ptr2( []( int var ){
        std::cout << "func_pointer2 var: " << var << std::endl;
    } );


    list.push_back( std::thread( []{
        std::cout << "lambda 1" << std::endl;
    }));
    ( --list.end() )->join();

    list.push_back( std::thread( func_pointer, 4 ) );
    ( --list.end() )->join();

    list.push_back( std::thread( func_ptr2,    3 ) );
    ( --list.end() )->join();


    list.push_back( std::thread( [ &variable ]() {
        std::cout << "lambda 4 variable: " << variable << std::endl;
        variable--;
    } ) );
    ( --list.end() )->join();

    std::cout << "variable: " << variable << std::endl;

    return 0;
}
