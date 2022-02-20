#include <iostream>

class SomeVictim
{
  int member_1, member_2;
public:
  SomeVictim(int value_1, int value_2) : member_1(value_1), member_2(value_2) {}
  
};

void func( int *int_ptr )
{
  std::cout << "i'm kind of int " << *int_ptr << std::endl;
}

int main()
{
  SomeVictim ex(33,405);
  func( reinterpret_cast<int*>(&ex) );
}
