#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <list>

void func_1( std::mutex *m )
{
  m->lock();
  std::cout << "func_1 lock"   << std::endl;

  std::this_thread::sleep_for( std::chrono::milliseconds( 3000 ) );

  std::cout << "func_1 unlock" << std::endl;
  m->unlock();
}

void func_2( std::mutex *m )
{
  m->lock();
  std::cout << "func_2 lock"   << std::endl;

  std::this_thread::sleep_for( std::chrono::milliseconds( 50 ) );

  std::cout << "func_2 unlock" << std::endl;
  m->unlock();
}

int main()
{

  std::mutex m;
  std::mutex m2;
  std::list< std::thread > list;
  list.push_back(  std::thread( func_1, &m )  );
  list.push_back(  std::thread( func_2, &m2 )  );

for( std::thread &th : list )
    th.join();

  return 0;
}
