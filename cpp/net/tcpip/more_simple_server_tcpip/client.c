#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include "functions.h"

int main()
{
	int client_fd = Socket( AF_INET, SOCK_STREAM, 0 );

	struct sockaddr_in addr;
	memset( &addr, 0, sizeof( struct sockaddr_in ) );
	addr.sin_family = AF_INET;
	addr.sin_port = htons( 28650 );
	Inet_pton( AF_INET, "127.0.0.1", &addr.sin_addr );

	Connect( client_fd, (struct sockaddr *)&addr, sizeof addr );

	write( client_fd, "Hello\n", 6);

	char buf[256];

	ssize_t nread;

	nread = read( client_fd, buf, 256 );
	
	if( nread == -1 )
	{
		perror("read failed");
		exit(EXIT_FAILURE);
	}
	if( nread == 0 )
	{
		printf("EOF occured\n");
	}

	write( STDOUT_FILENO, buf, nread);
	
	sleep( 10 );
	close( client_fd );
}
