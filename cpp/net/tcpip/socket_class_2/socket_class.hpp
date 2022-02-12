
class System_resource
{
   typedef int fd_type;
	fd_type sock;	

public:

	System_resource();
	virtual ~System_resource();
}

class Socket : public System_resource
{

public:
	Socket();

	virtual ~Socket() = default;

}
