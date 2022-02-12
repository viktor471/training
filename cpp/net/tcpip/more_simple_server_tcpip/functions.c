#include "functions.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>

int Socket( int domain, int type, int protocol )
{
	int result = socket( domain, type, protocol );

	if( result == -1 )
	{
		perror( "ERROR in Socket" );
		exit( EXIT_FAILURE );
	}

	return result;
	
}

void Bind( int sockfd, const struct sockaddr* addr, socklen_t addrlen )
{
	int result = bind( sockfd, addr, addrlen );

	if( result == -1 )
	{
		perror("bind failed");
		exit( EXIT_FAILURE );
	}
}

void Listen( int sock_fd, int backlog )
{
	int result = listen( sock_fd, backlog );

	if( result == -1 )
	{
		perror("listen failed");
		exit(EXIT_FAILURE);
	}
}

int Accept( int sock_fd, struct sockaddr *addr, socklen_t *addrlen)
{
	int result = accept( sock_fd, addr, addrlen );

	if( result == -1 )
	{
		perror("accept failed");
		exit( EXIT_FAILURE );

	}
	return result;
}

void Connect( int sock_fd, const struct sockaddr *addr, socklen_t addrlen )
{
	int result = connect( sock_fd, addr, addrlen );

	if( result == -1 )
	{
		perror("inet_pton failed");
		exit( EXIT_FAILURE );
	}
}

void Inet_pton( int af, const char* src, void *dst )
{

	int result = inet_pton( af, src, dst );

	if( result == 0 )
	{
		printf("Inet_pton failed: src does not contain a character"
				 " string representing a valid network addres in the specified"
				 " address family\n");
		exit( EXIT_FAILURE );
	}
	if( result == -1 )
	{
		perror("inet_pton failed");
		exit( EXIT_FAILURE );
	}
}


