#include <iostream>

using namespace std;

class A : std::greater<double>
{
  double content;
public:
  A() = default;
  A( double value ) : content( value ) {}
  void print_another_value( const A &another )
  {
    std::cout << another.content << std::endl;
  }
};


int main()
{
  A ex_1;
  ex_1.print_another_value( 4.5 );
  return 0;
}
