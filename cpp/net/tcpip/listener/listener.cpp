//For Socket-API
#include <sys/socket.h>

// My headers
#include "listener.hpp"

Listener::Listener() :
	_all_sockets{}
{}

Listener::add( fd_t new_socket )
{
	FD_SET( new_socket, &_all_sockets );
	set_maxfd( new_socket );
}

Listener::set_maxfd( fd_t new_socket )
{
	if( _max_fd < new_socket )
		_max_fd = new_socket;
}

void Listener::listen( fd_t new_socket )
{
	::listen( new_socket, _number_pending_connections );
}

void Listener::set_number_pending_connections( uint16_t number )
{
	_number_pending_connections = number;	
}
