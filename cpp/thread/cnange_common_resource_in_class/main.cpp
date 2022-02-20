#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <list>

class A
{
public:
  int _var;
  std::mutex m;
  std::list< std::thread > list;
  A( int var_ = 9 ) : _var(var_) {}

  void func()
  {
    m.lock();
    for( int i = 0; i < 100; i++ )
    {
      std::cout << _var << std::endl;
    }
    m.unlock();
  }

  void func_2()
  {
    std::this_thread::sleep_for( std::chrono::microseconds(10) );
    _var = 777;
  }

  void add_functions()
  {
    list.push_back( std::thread( &A::func, this ) );
    list.push_back( std::thread( &A::func_2, this ) );
  }

  void join()
  {
    for( std::thread& th : list )
      th.join();
  }
};

int main()
{
  A a(8);
  a.add_functions();
  a.join();

  return 0;
}
