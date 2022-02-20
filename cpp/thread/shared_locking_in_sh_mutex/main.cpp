#include <iostream>
#include <shared_mutex>
#include <mutex>
#include <chrono>
#include <thread>
#include <list>

void func( int id, std::shared_timed_mutex* m )
{
  m->lock_shared();

  for( int i = 0; i < 10000; i++ )
  {
    //std::this_thread::sleep_for( std::chrono::milliseconds(10));
    std::cout << "I am thread #" << id << std::endl;
  }

  m->unlock_shared();
}

int main()
{
  std::shared_timed_mutex m;
  std::list< std::thread > list;

  for( int id : { 1,2,3,4,5 } )
    list.push_back( std::thread( func, id, &m ));

  for( std::thread &th : list )
    th.join();

  return 0;
}
