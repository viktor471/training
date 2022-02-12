#ifndef END_POINT_HPP
#define END_POINT_HPP

#include <string>
#include <cstdint>
#include <chrono>
#include <string.h>
#include <netinet/in.h>

const int    PENDING_CONNECTIONS = 4;
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

  End_point( std::string&& s_addr, in_port_t sin_port );
  End_point( const in_addr_t& s_addr, in_port_t sin_port );

protected:

  enum PeerName
  {
    SERVER,
    CLIENT
  };


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
  timeval     _select_timeout;

  sockaddr_in _client;
  sockaddr_in _server;
  socklen_t   _socklen;

  Socket      _connection_sock;
  Socket      _data_sock;

  fd_set      _all_set;
  short       _ready_connection_sockets;
  short       _max_fd;

  char        _buffer[BUF_SIZE];
  int         _read_size;
  bool        _is_data_for_sending;

  int         _result;

  Socket socket();

  void   bind();
  void   listen();
  void   connect();
  void   shutdown();
  void   close();
  void   set_reuse_addr();


  void     set_reuse_addr( Socket sock );
  void     select( fd_set &read_set, fd_set &write_set );
  timeval  set_select_timeval( const timeval &tm = {0,0} );
  timeval  get_select_timeval() const;
  void     rebuild_set(       Socket      sock_  );
  void     set_maxfd  (       short       new_   );
  short    get_ready_connection_sockets() const;

  Socket accept();
  void   write( const std::string& msg );
  int    read();
  int    write();


  sockaddr *initilize_connection_sockaddr( const in_addr_t& s_addr_,
                                                 in_port_t  sin_port_ );

  void configuring();
  void close_connection();

  void inet_pton( const std::string& address );
  void inet_ntop( sockaddr_in &addr, char buf[ ADDR_LENGTH ] );
  void inet_net_pton(       std::string &&addr );
  sockaddr *get_sockaddr( PeerName     peer_name_ );
  sockaddr *get_sockaddr( sockaddr_in& addr       );

  void perror        ( const std::string &msg   ) const;

  void show_addr_port( const std::string  &msg,
                       const HR_addr_port &addr );
  void show_received_buf();
  void get_sock_name( Socket sock_fd, sockaddr_in &addr );
  HR_addr_port get_hum_read_addr_port( Socket sock_fd );

};

#endif
