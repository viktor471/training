#include <iostream>

using namespace std;

class A
{
public:
int inner_var = 3;
  A( int var ) : inner_var(var)
  { std::cout << "A constructor"    << std::endl; }

  A( const A&  another )
  { std::cout << "copy constructor" << std::endl; }

  A(       A&& another )
  { std::cout << "move constructor" << std::endl; }

  A& operator=( const A&  another )
  { std::cout << "copy assignment"  << std::endl; }

  A& operator=(       A&& another )
  { std::cout << "move assignment"  << std::endl; }

  ~A(){ std::cout << "A destructor "    << std::endl; }

};

int main()
{
  const A& const_ref_to_rvalue = 33;
  return 0;
}
