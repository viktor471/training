#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <iomanip>
#include "server.hpp"

void Server::run()
{
  std::cout << "run" << std::endl;

  while( FOREVER )
  {

    fd_set read_set  = _all_set,
           write_set = _all_set;

    select( read_set, write_set );

    if( _ready_connection_sockets > 0 )
    {
      if( FD_ISSET( _connection_sock, &read_set  ) )
        accept();
      if( FD_ISSET( _data_sock,       &read_set  ) )
        read();
      if( FD_ISSET( _data_sock,       &write_set ) )
        write();
    }

  }

  std::cout << "end" << std::endl;

}


void Server::configuring()
{
    socket();
    set_reuse_addr();
    bind();
    listen();
    rebuild_set( _connection_sock );
}

void Server::set_reuse_addr()
{
    End_point::set_reuse_addr(_connection_sock);
}

Server::Server( const in_addr_t& s_addr, in_port_t sin_port ) :
    End_point( s_addr, sin_port )
{
  initilize_connection_sockaddr( s_addr, sin_port );
  configuring();
}


