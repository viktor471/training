#include <QCoreApplication>
#include <thread>
#include <list>
#include <iostream>


void do_work( std::thread &th )
{
    for( int i = 0; i < 100; i++ )
    {
        std::cout << i << " " << std::this_thread::get_id() <<  std::endl;
        if( i == 50 )
            th.join();

    }
}

void do_work2()
{
    for( int i = 0; i < 100; i++ )
    {
        std::cout << i << " " << std::this_thread::get_id() << std::endl;
    }
}

int main()
{

    std::list< std::thread > list;

    list.push_back( std::thread( do_work2 ) );

    list.push_back( std::thread( do_work, std::ref( list.begin().operator*() ) ) );

    for( int i = 0; i < 100; i++ )
    {
        std::cout << i << " main" << std::endl;
    }


    list.pop_front();

    for( std::thread &th : list )
       th.join();

    return  0;
}
