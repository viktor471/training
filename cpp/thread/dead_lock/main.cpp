#include <iostream>
#include <thread>
//#include <chrono>
#include <mutex>
#include <list>

void func_1( std::mutex *m1, std::mutex *m2 )
{
    m1->lock();
    std::cout << "func_1 m1.lock() "   << std::endl;

    std::this_thread::sleep_for( std::chrono::milliseconds(1000));
    m2->lock();
    std::cout << "func_1 m2.lock() "   << std::endl;

    m1->unlock();
    std::cout << "func_1 m1.unlock() " << std::endl;

    m2->unlock();
    std::cout << "func_1 m2.unlock() " << std::endl;
}


void func_2( std::mutex *m1, std::mutex *m2 )
{

    m2->lock();
    std::cout << "func_2 m2.lock() "   << std::endl;

    m1->lock();
    std::cout << "func_2 m1.lock() "   << std::endl;

    m2->unlock();
    std::cout << "func_2 m2.unlock() " << std::endl;

    m1->unlock();
    std::cout << "func_1 m1.unlock() " << std::endl;

}


int main()
{
    std::list< std::thread > list;

    std::mutex m1;
    std::mutex m2;

    list.push_back( std::thread( func_1, &m1, &m2 ));
    list.push_back( std::thread( func_2, &m2, &m2 ));

    for( std::thread &th : list )
        th.join();

    return 0;
}
