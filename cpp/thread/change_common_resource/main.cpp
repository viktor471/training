#include <iostream>
#include <mutex>
#include <thread>
#include <list>
#include <chrono>

void func_1( std::mutex *m, int* var )
{
  m->lock();
  std::cout << "func_1 lock" << std::endl;
  for( int i = 0; i < 100; i++ )
  std::cout << *var << std::endl;
  m->unlock();
}

void func_2( int* var )
{
  std::this_thread::sleep_for( std::chrono::microseconds(10) );
  *var = 999;
}


int main()
{
  int var = 5;
  std::list< std::thread > list;
  std::mutex m;
  list.push_back( std::thread( func_1, &m, &var) );
  list.push_back( std::thread( func_2, &var ) );

  for( std::thread& th : list )
    th.join();

  return 0;
}
