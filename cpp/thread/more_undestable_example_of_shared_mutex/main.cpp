#include <iostream>
#include <shared_mutex>
#include <mutex>
#include <thread>
#include <chrono>
#include <list>
#include <fstream>


int counter =0;
std::ofstream file("file");

void shared_lock( std::shared_timed_mutex *m )
{
    std::loc
   std::this_thread::sleep_for( std::chrono::nanoseconds( 100'100 ) );
   m->lock_shared();

   int id = ++counter;

   for( int i = 0; i < 1000; i++ )
        file << "I am " << id << std::endl;

   m->unlock_shared();
}

void common_lock( std::shared_timed_mutex *m )
{
//    std::this_thread::sleep_for( std::chrono::nanoseconds(1) );
    m->lock();

    for( int i = 0; i < 1000; i++ )
        file << "I am awake" << std::endl;
    m->unlock();
}

int main()
{
    std::shared_timed_mutex m;

    std::list< std::thread > list;
    for( int i = 0; i < 10; i++ )
        list.push_back( std::thread( shared_lock, &m ) );

    list.push_back( std::thread( common_lock, &m ) );

    for( std::thread& th : list )
        th.join();

    file.close();

    return 0;
}
