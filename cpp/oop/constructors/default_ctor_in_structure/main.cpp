#include <iostream>
#include <string>

struct A
{
  int a;// = 3;
  int b;// = 44;
  std::string text = "hello";
  A() = default;
//  A() {};
//  A( int a = 6, int b = 66, const std::string &text = "bye") :
//    a(this->b), b(b), text(text) {}

};

int main()
{
  A a = A();
  std::cout << a.a << " " << a.b << " " << a.text << std::endl;
    return 0;
}
