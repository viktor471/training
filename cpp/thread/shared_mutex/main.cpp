#include <iostream>
#include <mutex>
#include <shared_mutex>
#include <thread>
#include <chrono>

std::mutex cout_mutex;

void log( const std::string& msg )
{

  std::lock_guard< std::mutex > guard( cout_mutex );

  std::cout << msg << std::endl;

}

class Thread_safe_counter
{
private:

  mutable  std::shared_timed_mutex _mutex;
  unsigned int                     _value;

public:

  Thread_safe_counter() = default;

//Multiple threads/readers can read the counter's  value at the same time.
  unsigned int get() const
  {
    std::shared_lock< std::shared_timed_mutex > lock( _mutex );

    log("get() begin ");

    std::this_thread::sleep_for( std::chrono::milliseconds( 500 ) );

    auto result = _value;

    log("get() end");
    return result;
  }

  // Only one thread/writer can increment/write the counter's value.
  void increment()
  {
    std::unique_lock< std::shared_timed_mutex > lock( _mutex );
  }
  //Only one thread/writer can reset/write the counter's value
  void reset()
  {
    std::unique_lock< std::shared_timed_mutex > lock( _mutex );
  }

};

int main()
{
  Thread_safe_counter counter;
  auto increment_and_print = [&counter]()
  {

  }
  return 0;
}
