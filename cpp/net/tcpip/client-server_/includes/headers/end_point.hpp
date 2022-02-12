#ifndef END_POINT_HPP
  #define END_POINT_HPP

#include <string>
#include <cstdint>
#include <chrono>
#include <string.h>
#include <netinet/in.h>

const int    ON       = 1;
const int    FOREVER  = 1;
const int    BUF_SIZE = 1024;
const size_t MSG_SIZE = 10;

const int    ADDR_LENGTH         = strlen( "000.000.000.000");

const socklen_t  SOCKADDR_IN_LENGTH = sizeof( sockaddr_in );
typedef int Socket;

class End_point
{

public:
  typedef struct Hum_read_addr_port
  {

    std::string  _addr;
    uint16_t     _port;

    Hum_read_addr_port( const std::string& addr_ = "", uint16_t port_ = 0 ) :
      _addr(addr_) , _port(port_)  {}

  } HR_addr_port;

protected:

  class Timer
  {
      using hclock       = std::chrono::high_resolution_clock;
      using time_point   = hclock::time_point;
      time_point _start;
      time_point _end;
      long       _period;

  public:

      Timer( long period = 0 ) : _period( period ) {}

      void set_period( long period );
      void start();
      void end();
      auto elapsed();
      auto elapsed_from_start();
      bool is_elapsed();

  };

  Timer       _timer;
  char        _buffer[BUF_SIZE];
  Socket      _data_sock;
  sockaddr_in _server;
  fd_set      _all_set;

  short       _max_fd;
  short       _ready_connection_sockets;
  timeval     _select_timeout;

  socklen_t   _socklen;
  int         _result;

  void set_reuse_addr();

};

#endif
