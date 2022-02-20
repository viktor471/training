#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <functional>
#include <string>

enum JOIN_OR_DETACH
{
  JOIN,
  DETACH
};

template < class T >
class ThreadHandler
{
private:
  std::thread    _th;
  JOIN_OR_DETACH _choice;

public:
  ThreadHandler( std::function<T> func, JOIN_OR_DETACH choice = JOIN ) :
    _th    ( func   ),
    _choice( choice )
  {
    std::cout << "TH constructor " << std::endl;
  }

  ~ThreadHandler()
  {
    std::cout << "TH Destructor" << std::endl;

    if( _choice == JOIN   )
     _th.join();
    if( _choice == DETACH )
     _th.detach();
  }
};

class Functor
{
private:
  std::string _msg;
  int         _times;
  std::shared_ptr< std::mutex >  _mutex;

public:
  Functor( std::string msg, int times, std::mutex* m = NULL ) :
    _msg(msg), _times(times)
  {
    if( m == nullptr )
      _mutex.reset( new std::mutex );
    else
      _mutex.reset( m );
  }

  int operator()()
  {
    for( int i = 0; i < _times; i++ )
      std::cout << "functor " << _msg << std::endl;
    return 55;
  }
};

int main()
{
  std::mutex m;
  ThreadHandler<int()> handler ( Functor("1", 55,  &m ) );
  ThreadHandler<int()> handler2( Functor("2", 100, &m ) );

  return 0;
}
