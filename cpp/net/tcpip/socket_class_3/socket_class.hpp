// For Socket-API
#include <sys/socket.h>
#include <netinet/in.h>

const int USING_PROTOCOL = 0;
const int ON             = 1;

class System_resource
{
public:
	System_resource()          = default;
	virtual ~System_resource() = default;
	
};

class Socket_t : public System_resource
{
   typedef  int                 fd_t;
  	typedef  struct sockaddr_in  sockaddr_in;
	typedef  struct sockaddr     sockaddr;

	fd_t         _sock;	
  	sockaddr_in  _address; 

	void inet_net_pton( const std::string &address );
	void socket();
	void initialize( const in_addr_t& s_addr, in_port_t sin_port );
	void initialize( const std::string& s_addr, in_port_t sin_port );
	void configuring();
   void set_reuse_addr();
	sockaddr* get_sockaddr();


public:
	Socket_t( const in_addr_t&  s_addr   = INADDR_ANY,
                   in_port_t   sin_port = 28650       );
	
   Socket_t( const std::string& s_addr, in_port_t sin_port );

	void bind();
	
	virtual ~Socket_t();

};
