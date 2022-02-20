#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <string>
#include <list>

int counter = 0;

void func( std::mutex *m, int id )
{
  for( int i = 0; i <20; i++ )
    std::cout << counter++ << "=======" << id << std::endl;

  std::cout << counter++ << '=======' << "end \"" << id << '"' << std::endl;

  m->unlock();
}

void func2( std::mutex *m, int id )
{
  m->lock();
  for( int i = 0; i < 1000; i++ )
    std::cout << counter++ << ":" << id << std::endl;

  std::cout << counter++ << ':' << "end \"" << id << '"' << std::endl;
}

int main()
{
  std::mutex m;
  std::list< std::thread > list;
  list.push_back( std::thread(func2, &m, 1) );
  list.push_back( std::thread(func2, &m, 2) );
  list.push_back( std::thread(func,  &m, 3) );

  for( std::thread &th : list )
    th.join();

  return 0;
}
