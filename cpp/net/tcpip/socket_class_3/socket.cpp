// For Socket-API
#include <sys/socket.h>
#include <unistd.h>
#include <string>
#include <cstring>
#include <arpa/inet.h>

// Common
#include <iostream>

// My headers
#include "socket.hpp"


Socket_t::Socket_t( const std::string& s_addr, in_port_t sin_port ) :
	System_resource(),
	_address{},
	_sock(0)
{
	initialize( s_addr, sin_port );
	configuring();
}

Socket_t::Socket_t( const in_addr_t& s_addr, in_port_t sin_port ) :
	System_resource(),
	_address{},
	_sock(0)
{
	initialize( s_addr, sin_port );	
   configuring();
}

void Socket_t::initialize( const std::string& s_addr, in_port_t sin_port )
{
	inet_net_pton(  std::move( s_addr )  );

	_address.sin_port   = htons( sin_port );
	_address.sin_family = AF_INET;
}

void Socket_t::initialize( const in_addr_t& s_addr, in_port_t sin_port )
{
	_address.sin_addr.s_addr = htonl( s_addr   );
	_address.sin_port        = htons( sin_port );
	_address.sin_family      = AF_INET;
}

void Socket_t::configuring()
{
	socket();
	set_reuse_addr();
}

void Socket_t::bind()
{
	sockaddr* address = get_sockaddr();
   
	address->sa_family = AF_INET;

	int result = ::bind( _sock, address, sizeof ( address )  );

   if( result == 0 )
		std::cerr << std::strerror(errno) << std::endl;
}

void Socket_t::socket()
{
	_sock = ::socket( AF_INET, SOCK_STREAM, USING_PROTOCOL );
	if( _sock == 0 )
		std::cerr << std::strerror(errno) << std::endl;
}

void Socket_t::set_reuse_addr()
{
  int result = setsockopt( _sock,
	                        SOL_SOCKET,
	                        SO_REUSEADDR,
	                        (char *)&ON,
	                        sizeof(ON) );

  	if( result == 0 )
  		std::cerr << std::strerror(errno) << std::endl;
}

sockaddr* Socket_t::get_sockaddr()
{
	return reinterpret_cast<sockaddr*>(&_address);
}

Socket_t::~Socket_t()
{
	if( _sock != 0 )
		close(_sock);
	_sock = 0;
}

void Socket_t::inet_net_pton( const std::string &address )
{
	std::string copy;

	if( address == "" )
		copy = "127.0.0.1";
	else
		copy = address;

   	int result = ::inet_net_pton(  AF_INET,
                                     copy.c_str() ,
                                     (struct in_addr*)&(_address.sin_addr),
                                     sizeof( in_addr ) );
	if( result == 0 )
		std::cerr << std::strerror(errno) << std::endl;

}

