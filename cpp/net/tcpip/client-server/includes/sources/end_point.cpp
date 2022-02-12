#include "end_point.hpp"
#include <iostream>
#include <iomanip>
#include <arpa/inet.h>
#include <unistd.h>

void End_point::Timer::set_period(long period)
{
    _period = period;
}

sockaddr *End_point::initilize_connection_sockaddr( const in_addr_t& s_addr_,
                                                 in_port_t sin_port_ )
{
  memset(&_server, 0, SOCKADDR_IN_LENGTH );
  memset(&_client, 0, SOCKADDR_IN_LENGTH );

// нужен ли htonl

  _server.sin_addr.s_addr = htonl( s_addr_   );
  _server.sin_port        = htons( sin_port_ );
  _server.sin_family      = AF_INET;

  _connection_sock = 0;
  _data_sock       = 0;
  _is_data_for_sending = false;
  memset( _server.sin_zero, 0, sizeof( _server.sin_zero )  );

  _max_fd = 0;
  _read_size    = 0;
  FD_ZERO(&_all_set);

  set_select_timeval( {0,0} );

  return get_sockaddr( SERVER );
}


void End_point::bind()
{
  sockaddr* addr = get_sockaddr(SERVER);
  addr->sa_family = AF_INET;

  _result = ::bind(  _connection_sock, addr, sizeof ( struct sockaddr)  );

  perror("bind()");
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

void End_point::listen()
{
  _result = ::listen( _connection_sock, PENDING_CONNECTIONS );
  perror("listen()");
}


Socket End_point::accept()
{
  _data_sock = ::accept( _connection_sock, get_sockaddr( CLIENT ), &_socklen );

  if( _data_sock == -1 )
    perror("accept(): ");

  _ready_connection_sockets--;
  rebuild_set( _data_sock );

  HR_addr_port addr_and_port = get_hum_read_addr_port( _data_sock );

  show_addr_port( "connect", addr_and_port );

  return _data_sock;
}



End_point::End_point( std::string&& s_addr, in_port_t sin_port ) :
  _timer(0),
  _select_timeout(),
  _client(),
  _server(),
  _socklen(0),
  _connection_sock(0),
  _data_sock(0),
  _ready_connection_sockets(0),
  _max_fd(0),
  _read_size(0),
  _is_data_for_sending(false),
  _result(0)
{
  FD_ZERO(&_all_set);
  inet_net_pton(  std::move( s_addr )  );

  _server.sin_port    = htons( sin_port );

  _server.sin_family  = AF_INET;

  memset( _server.sin_zero, 0, sizeof( _server.sin_zero )  );

  configuring();

}

End_point::End_point(const in_addr_t &s_addr, in_port_t sin_port)
{
  initilize_connection_sockaddr( s_addr, sin_port );
  configuring();
}


int End_point::read()
{
  int read_size = recv( _data_sock, _buffer, BUF_SIZE, 0 );

  if( read_size <= 0 )
    perror("recv: ");
  else
  {
    _is_data_for_sending = true;
    _read_size           = read_size;

    Hum_read_addr_port addr_and_port = get_hum_read_addr_port( _data_sock );

    show_addr_port( "read", addr_and_port );

    show_received_buf();
  }

  return read_size;
}


void End_point::select( fd_set &read_set, fd_set &write_set )
{

    timeval tm = _select_timeout;

    _result = ::select( _max_fd + 1, &read_set, &write_set, NULL, &tm );

    _ready_connection_sockets = _result;

    perror("select()");
}


int End_point::write()
{
  if( _is_data_for_sending )
  {
    _is_data_for_sending = false;

    int &size_for_sending = _read_size;
    uint16_t sended_size
            = send( _data_sock, _buffer, size_for_sending, 0 );

    if( sended_size <= 0 )
      perror("send: ");

    size_for_sending -= sended_size;

    return sended_size;
  }
  else
      return 0;
}

void End_point::configuring()
{
    socket();
    set_reuse_addr();
    bind();
    listen();
    rebuild_set( _connection_sock );
}


void End_point::rebuild_set( Socket sock_ )
{
  FD_SET( sock_, &_all_set );
  set_maxfd( sock_ );
}


void End_point::show_addr_port( const std::string                  &msg,
                             const HR_addr_port &addr_and_port )
{
  std::cout << std::setw(10)
            << std::left
            << msg
            << " "
            << addr_and_port._addr
            << ":"
            << addr_and_port._port
            << std::endl;
}


void End_point::get_sock_name( Socket sock_fd, sockaddr_in &addr_in )
{
  sockaddr* addr   = get_sockaddr( addr_in );
  socklen_t length = SOCKADDR_IN_LENGTH;

  _result = ::getsockname( sock_fd, addr, &length );

  perror( "getsockname()" );
}


void End_point::inet_ntop( sockaddr_in &addr, char buf[ADDR_LENGTH] )
{
   if( ::inet_ntop( AF_INET, &addr.sin_addr, buf, SOCKADDR_IN_LENGTH ) == NULL )
       _result = -1;

   perror( "inet_ntop" );
}


void End_point::show_received_buf()
{
    std::string received_string;

    received_string.append( _buffer, _read_size );

    std::cout << "received_string: "
              <<  received_string
              << std::endl;

    for( int i = 1; i < _read_size; i++ )
    {
      std::cout << " ";

      std::cout << std::hex << std::setw(2)
                << (int)_buffer[i];
    }

    std::cout << std::endl;

}

void End_point::close_connection()
{
    shutdown();
    close();
}

void End_point::shutdown()
{
    _result = ::shutdown( _data_sock, SHUT_RDWR );

    perror( "shutdown" );
}

void End_point::close()
{
   _result = ::close( _data_sock );

   perror( "close" );
}


Socket End_point::socket()
{
  _connection_sock = ::socket( PF_INET, SOCK_STREAM, 0 );
  _result = _connection_sock;

  perror("socket()");

  rebuild_set( _connection_sock );

  return _connection_sock;
}

sockaddr *End_point::get_sockaddr( PeerName peer_name_ )
{
  if     ( peer_name_ == SERVER )
    return get_sockaddr( _server );
  else if( peer_name_ == CLIENT )
    return get_sockaddr( _client );
  else
  {
    std::cerr << "peer_name_ wasn't recognized in get_sockaddr";

    return nullptr;
  }
}


sockaddr *End_point::get_sockaddr( sockaddr_in& addr )
{
  return reinterpret_cast<sockaddr*>(&addr);
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


short End_point::get_ready_connection_sockets() const
{
  return _ready_connection_sockets;
}


timeval End_point::set_select_timeval( const timeval &tm )
{
  return _select_timeout = tm;
}


timeval End_point::get_select_timeval() const
{
  return _select_timeout;
}


End_point::HR_addr_port
End_point::get_hum_read_addr_port( Socket sock_fd )
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


void End_point::inet_net_pton( std::string &&addr )
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


void End_point::set_maxfd( short new_ )
{
  if( _max_fd < new_ )
      _max_fd = new_;
}


