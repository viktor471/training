#ifndef FUNCTIONS_HPP
	#define FUNCTIONS_HPP

#include <sys/socket.h>

int  Socket( int domain, int type, int protocol );

void Bind  ( int sockfd, const struct sockaddr* addr, socklen_t addrlen );

void Listen( int sock_fd, int backlog );

int  Accept( int sock_fd, struct sockaddr *addr, socklen_t *addrlen);

void Connect( int sock_fd, const struct sockaddr *addr, socklen_t addrlen );

void Inet_pton( int af, const char* src, void *dst );

#endif //FUNCTIONS_HPP
