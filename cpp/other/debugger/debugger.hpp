#include <fstream>
#include <string>
#include <iostream>

class Debugger
{
	static  std::ostream &stream;
public:
	Debugger( const std::string  &name_of_file             );
	Debugger( const std::ostream &stream       = std::cerr );

	template< typename T>
	operator<<( const std::string &msg );
}
