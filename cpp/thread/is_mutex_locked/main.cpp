#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>

void func( std::mutex *m )
{

  m->lock();
  std::cout << "func lock"   << std::endl;

  std::this_thread::sleep_for( std::chrono::milliseconds(1000) );

  std::cout << "func unlock" << std::endl;
  m->unlock();

}

int main()
{
  std::mutex m;

  std::thread th( func, &m );


//  std::this_thread::sleep_for( std::chrono::microseconds(10) );
  std::this_thread::sleep_for( std::chrono::milliseconds(2000) );

  if( m.try_lock() )
  {
    std::cout << "m was locked in main thread" << std::endl;
    m.unlock();
    std::cout << "m was unlocked in main thread " << std::endl;
  }

  th.join();

  return 0;
}
