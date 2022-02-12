#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>
#include <string>
#include <list>
#include <fstream>

int counter_row = 0;
int counter = 0;

void lock( std::mutex *m, std::ofstream* stream )
{
    std::ofstream& out = *stream;

    m->lock();
    int id = ++counter;

    for( int i = 0; i < 1000; i++ )
        out << counter_row++ << ": " << id << std::endl;

    out << counter_row++ << ": end of " << id << std::endl;
}

void unlock_from_another_thread( std::mutex *m, std::ofstream* stream )
{
    std::ofstream& out = *stream;

    //std::this_thread::sleep_for( std::chrono::nanoseconds(500) );
    std::ofstream sec("sec");
    for( int i = 0; i < 100; i++ )  sec << "nothing" << std::endl;
    int id = ++counter;
    sec.close();
    m->unlock();
    out << counter_row++ << ": " << id << std::endl;
}

int main()
{
    std::mutex m;
    std::list< std::thread > list;
    std::ofstream stream("file");

    list.push_back( std::thread( lock, &m, &stream ) );
    list.push_back( std::thread( lock, &m, &stream ) );
    list.push_back( std::thread( unlock_from_another_thread, &m, &stream ) );


    for( std::thread& th : list )
        th.join();

    stream.close();
    return 0;
}
