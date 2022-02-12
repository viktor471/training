#ifndef CLIENT_H
#define CLIENT_H

#include <netinet/in.h>
#include <string>
#include <cstdint>

typedef int Socket;
typedef struct sockaddr_in sockaddr_in;

const uint16_t BUF_LEN = 1024;

class Client
{
  void socket();
  void connect();
  void write( const std::string& msg );
  void inet_pton( const std::string& address );
  void select();
  void read();

private:

  Socket      _client;
  sockaddr_in _server_addr_in;
  char        _bufer[ BUF_LEN ];

public:
  Client();

};

#endif // CLIENT_H
