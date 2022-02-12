#include <QCoreApplication>
#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <list>
#include <QSharedDataPointer>
#include <iomanip>

  std::mutex m;

void test()
{
  std::lock_guard< std::mutex > lock( m );
  std::this_thread::sleep_for( std::chrono::milliseconds(1000) );
  std::this_thread::sleep_for( std::chrono::milliseconds(1000) );
  lock.~lock_guard();

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

  void output_ms()
  {
    std::cout <<  std::fixed
              <<  measure_delta().count() / 1E6
              <<  " ms"
              <<  std::endl;

  }
};

int main()
{
  Mes_time mes;
  mes.start();
  std::list< std::thread > list;
  list.push_back(  std::thread( test )  );
  list.push_back(  std::thread( test )  );

  for( std::thread &th : list )
    th.join();
  mes.end();

  mes.output_ms();
  return 0;
}
