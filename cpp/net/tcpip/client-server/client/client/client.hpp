#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <netinet/in.h>
#include <string>
#include <cstdint>
#include "end_point.hpp"

typedef int Socket;
typedef struct sockaddr_in sockaddr_in;

const uint16_t BUF_LEN = 1024;

class Client
{
  private:

  Socket      _client;
  sockaddr_in _server_addr_in;
  char        _bufer[ BUF_LEN ];

public:
  Client();

};

#endif // CLIENT_HPP
