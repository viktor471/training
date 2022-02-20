#include <iostream>

struct A
{
public:
  short b, c;
  A(int a){ b = a; c = a; }
};

struct B
{

public:
B(int a ) : _a(a) {}
int _a;
operator A() const { return A(_a);}

};

int main()
{
  int int_a =3;
  const A& a_1 = int_a;
  B b_1(2);
  const A &a_2 = b_1;

  std::cout << a_2.b << std::endl;
  return 0;
}
