// Common headers
#include <cstdint>

enum Events{
	Accepting = 0b0001,

}
struct EndPoint
{
	EndPoint( uint32_t ip, uint16_t port );
}

class Listener
{
	typedef int fd_t;

	fd_set   _all_sockets;
	fd_t     _max_fd;
	timeval  _wait_timeout;
	uint16_t _number_pending_connections;

	Listener();
	public:

	add( const EndPoint& end_point, );
	set_number_pending_connections( uint16_t number );
	set_maxfd( fd_t new_socket );

};
