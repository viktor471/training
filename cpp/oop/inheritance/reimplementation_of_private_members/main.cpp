#include <iostream>

class A
{
protected:
  int private_member = 9;
  private:

  int  decrement()    { return private_member--; };
  void private_func()
  {
    std::cout << "private func" << std::endl;
  }

  public:

  void call_private_func()
  {
    private_func();
  }

  void i_am_bigger_than_zero()
  {
    if( decrement() > 0 )
      std::cout << "i am bigger then zero " << private_member << std::endl;
  }


};

class B : public A
{
  public:
  int decrement() { return private_member++; }
  void private_func()
  {
    std::cout << "now I am public func" << std::endl;
  }
};

int main()
{
  A ex_1;
  ex_1.call_private_func();

  B ex_2;
  ex_2.private_func();

  ex_2.i_am_bigger_than_zero();
  ex_2.i_am_bigger_than_zero();
  ex_2.i_am_bigger_than_zero();
  ex_2.i_am_bigger_than_zero();
  return 0;
}
