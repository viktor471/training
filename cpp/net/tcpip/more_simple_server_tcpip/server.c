#include <sys/types.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
#include "functions.h"

int main()
{
	struct sockaddr_in addr = {0};
	addr.sin_family = AF_INET;
	addr.sin_port   = htons( 28650 );
	
	socklen_t addrlen = sizeof( addr );

	ssize_t nread;
	char buf[ 256 ];

	int server = Socket( AF_INET, SOCK_STREAM, 0 );
	
	Bind( server, (struct sockaddr *) &addr, sizeof addr );

	Listen( server, 5);

	int active_fd = Accept( server, (struct sockaddr *) &addr, &addrlen );
	
	nread = read( active_fd, buf, 256 );

	if( nread == 0 )
	{
		printf("END OF FILE occured\n");
	}
	
	write( STDOUT_FILENO, buf, nread );
	write( active_fd, buf, nread );

	sleep(15);

	close(active_fd);
	close(server);

   return 0;
}
