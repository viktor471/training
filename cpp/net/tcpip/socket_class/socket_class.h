#ifndef SOCKET_CLASS_H
#define SOCKET_CLASS_H

#include <string>

// for Socket-API
#include <netinet/ip.h>

class Socket
{

    typedef int fd_type;

    fd_type     _conn_sock;
    socklen_t   _socklen;
    sockaddr_in _address;
    timeval     _wait_timeout;

    void inet_net_pton( std::string &&addr );
    void initialize();


public:

  Socket( std::string&& s_addr, in_port_t sin_port );

End_point::End_point(const in_addr_t &s_addr, in_port_t sin_port)
{
  initilize_connection_sockaddr( s_addr, sin_port );
  configuring();
}

    ~Socket();
};

#endif // SOCKET_CLASS_H
