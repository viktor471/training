#include <iostream>
#include <cstdlib>
#include <sys/select.h>

using namespace std;

int main()
{

  fd_set rfds;
  struct timeval tv;
  int retval;

  FD_ZERO(&rfds);
  FD_SET(0, &rfds);

  tv.tv_sec = 5;
  tv.tv_usec = 0;

  retval = select(1, &rfds, NULL, NULL, &tv);

  if( retval == -1 )
    perror("select()");
  else if(retval)
    std::cout << "data is available now" << std::endl;
  else
    std::cout << "no data within 5 seconds" << std::endl;

  int a;
  std::cout <<"hello" << std::endl;
  std::cin >>  a ;
  return 0;
}
