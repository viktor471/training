#ifndef SERVER_HPP
#define SERVER_HPP

#include <iostream>
#include <errno.h>
#include <netinet/in.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <cstring>
#include <memory>
#include <iomanip>
#include "end_point.hpp"


typedef struct in_addr in_addr;

class Server : public End_point
{

private:

  void configuring();

public:

  Server( const in_addr_t& s_addr   = INADDR_ANY,
                in_port_t  sin_port = 28650       );

  Server( std::string  &&s_addr,
          in_port_t      sin_port = 28650 );

  void      run();

};

#endif // SERVER_HPP
