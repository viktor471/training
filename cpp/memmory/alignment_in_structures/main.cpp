#include <iostream>

struct S{
int   b;
short a;
short c;
S() : a(0), b(0), c(0) {}
};

using namespace std;

int main()
{
	S ex;
	ex.a = 3;
	ex.b = 3;
	ex.c = 3;
//	ex.d = 3;
	cout << "Hello World!" << endl;

	std::cerr << "sizeof(S)    "  << sizeof(S)    << std::endl;
	std::cerr << "sizeof(ex)   "  << sizeof(ex)   << std::endl;
	std::cerr << "sizeof(ex.a) "  << sizeof(ex.a) << std::endl;
	std::cerr << "sizeof(ex.b) "  << sizeof(ex.b) << std::endl;
	std::cerr << "sizeof(ex.c) "  << sizeof(ex.c) << std::endl;
	//std::cerr << "sizeof(ex.d) "  << sizeof(ex.d) << std::endl;

	std::cerr << sizeof (short);
	for(int i = 0; i < sizeof(S); i++)
	{
	  std::cerr << std::endl << i << std::endl;
	  for(int k = 0; k < 8; k++ )
	  {
		std::cerr << ((((char*)&ex)[i] & (1 << k))&&1);
		if(k != 0 && k != 7 ) if( !((k + 1)%4) ) std::cerr << " ";
	  }
	  std::cerr << std::endl;
	}

	std::cerr << std::endl;

	return 0;
}
