// For Socket-API
#include <sys/socket.h>
#include <unistd.h>

// My headers
#include "socket_class.hpp"

System_resource::System_resource()
{
	sock = socket();
}

System_resource::~System_resource()
{
	if( sock != 0 )
		close(sock);
	sock = 0;
}

Socket() : System_resource() {}
