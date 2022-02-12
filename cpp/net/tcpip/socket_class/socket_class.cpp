#include <iostream>

// for Socket-API
#include <arpa/inet.h>


#include "socket_class.h"

Socket::Socket() :
    conn_sock( socket() )
{
  address.sin_port    = htons( sin_port );

  address.sin_family  = AF_INET;

  memset( address.sin_zero, 0, sizeof( address.sin_zero )  );

}

void Socket::inet_net_pton( std::string &&addr )
{
        if( addr == "" )
      addr = "127.0.0.1";

    int _result = ::inet_net_pton(  AF_INET,
                                    addr.c_str() ,
                                    (struct in_addr*)&( address.sin_addr ),
                                    sizeof( in_addr ) );
    if( _result == 0 )
    {
        std::cerr << "Inet_pton failed: src does not contain a character"
                     " string representing a valid network addres in the"
                     "  specified address family "
                  << std::endl;
    }

    perror("inet_net_pton");


}

void Socket::initialize()
{

}

Socket::Socket(std::string &&s_addr, in_port_t sin_port)
  _wait_timeout{0},
  _socklen(0),
  _conn_sock(0),
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

}
