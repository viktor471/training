#include <iostream>

using namespace std;

int main()
{

  for( int i : (int[3]){1,2,3} )
    std::cout << "i: " << i << std::endl;


  for( int i : { 1, 2, 3 } )
    std::cout << "i: " << i << std::endl;

  for( int i ; i++ < 3; )
    std::cout << "i: " << i << std::endl;

  return 0;
}
