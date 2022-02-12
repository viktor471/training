#include "end_point.hpp"


void End_point::Timer::set_period(long period)
{
  _period = period;
}


void End_point::Timer::start()
{
  _start = hclock::now();
}


void End_point::Timer::end()
{
    _end = hclock::now();
}


auto End_point::Timer::elapsed()
{
  using namespace std::chrono;

    return duration_cast< microseconds >( _end - _start ).count();
}


auto End_point::Timer::elapsed_from_start()
{
  using namespace std::chrono;
  end();

  return duration_cast< microseconds >( _end - _start ).count();
}


bool End_point::Timer::is_elapsed()
{
  return elapsed_from_start() > _period;
}

void End_point::perror( const std::string &msg ) const
{
    if( _result == -1 )
        ::perror( msg.c_str() );
}


void End_point::set_reuse_addr( Socket sock )
{

  _result = setsockopt( sock,
                        SOL_SOCKET,
                        SO_REUSEADDR,
                        (char *)&ON,
                        sizeof(int) );

  perror("setsockopt()");

}


short Server::get_ready_connection_sockets() const
{
  return _ready_connection_sockets;
}


timeval Server::set_select_timeval( const timeval &tm )
{
  return _select_timeout = tm;
}


timeval Server::get_select_timeval() const
{
  return _select_timeout;
}


Server::HR_addr_port
Server::get_hum_read_addr_port( Socket sock_fd )
{
  sockaddr_in  addr_in;
  HR_addr_port addr_and_port;

  char buf[ ADDR_LENGTH ];

  memset( &addr_in, 0, SOCKADDR_IN_LENGTH );

  get_sock_name( sock_fd, addr_in );

  inet_ntop( addr_in, buf );

  addr_and_port._addr = std::string( buf );
  addr_and_port._port = ntohs( addr_in.sin_port );

  return addr_and_port;
}


void Server::inet_net_pton( std::string &&addr )
{
    if( addr == "" )
      addr = "127.0.0.1";

    _result = ::inet_net_pton(  AF_INET,
                                addr.c_str() ,
                                (struct in_addr*)&(_server.sin_addr),
                                sizeof( in_addr ) );
    if( _result == 0 )
    {
        std::cout << "Inet_pton failed: src does not contain a character"
                     " string representing a valid network addres in the"
                     "  specified address family "
                  << std::endl;
    }

    perror("inet_net_pton");

}


void Server::set_maxfd( short new_ )
{
  if( _max_fd < new_ )
      _max_fd = new_;
}


