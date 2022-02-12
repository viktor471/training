#include <QCoreApplication>
#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <list>
#include <QSharedDataPointer>


void test()
{
  std::mutex m;
  std::lock_guard< std::mutex > lock( m );
  std::this_thread::sleep_for( std::chrono::milliseconds(1000) );
}


class Mes_time
{
private:
  using time_point  = std::chrono::_V2::high_resolution_clock::time_point;
  using nanoseconds = std::chrono::nanoseconds;

  time_point _start;
  time_point _end;

  time_point gettime()
  {
    return std::chrono::high_resolution_clock::now();
  }

public:
  time_point start()
  {
    return _start = gettime();
  }

  time_point end()
  {
    return _end = gettime();
  }

  nanoseconds measure_delta()
  {
    return std::chrono::duration_cast< nanoseconds >( _end - _start );
  }
};

int main()
{

  std::list< std::thread > list;
  list.push_back(  std::thread( test )  );
  list.push_back(  std::thread( test )  );

  for( std::thread &th : list )
    th.join();
  return 0;
}
