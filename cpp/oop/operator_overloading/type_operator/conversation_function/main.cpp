#include <iostream>

class B{
public:
  int _member;
  B( int value ) : _member(value) { std::cout << "B constructor" << std::endl; }
  ~B()                            { std::cout << "B destructor"  << std::endl; }

};


class A{
public:
  int _member;
  A( int value ) : _member(value) { std::cout << "A constructor" << std::endl; }
  ~A()                            { std::cout << "A destructor"  << std::endl; }

  operator int() const
  {
//    return 88;
    return _member;
  }

  operator B() const
  {
    return B(_member);
  }
};


int main()
{
  A   a_a(3);

  int int_b = a_a;

  std::cout << "int_b:       " << int_b       << std::endl;

  B   b_a = a_a;

  std::cout << "b_a._member: " << b_a._member << std::endl;

  B   b_b(static_cast<int>(a_a));

  return 0;
}
