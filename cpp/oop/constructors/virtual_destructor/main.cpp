#include <QCoreApplication>
#include <iostream>
#include <QVariant>
#include <QDebug>

class Base
{
  public:
  Base( int c_ = 0, int d_ = 0 ) :
    _c(c_), _d(d_)
  {
    std::cout << "Base ctor"  << std::endl;
  }

//  virtual void method_1()
//  {
//    std::cout << "Base method_1" << std::endl;
//  }

//  void method_2()
//  {
//    std::cout << "Base method_2" << std::endl;
//  }

  ~Base()
  {
    std::cout << "Base dctor" << std::endl;
  }

  int _c, _d;
};


class Derived : public Base
{
public:
  Derived( int a_ = 0, int b_ = 0, int c_ = 0, int d_  = 0 ) :
  Base(c_, d_ ),
    _a(a_),
    _b(b_)
  {
    std::cout << "Derived ctor"   << std::endl;
  }

  ~Derived()
  {
    std::cout << "Derived dctor"  << std::endl;
  }

//  void method_1()
//  {
//    std::cout << "Derived method_1" << std::endl;
//  }

//  void method_2()
//  {
//    std::cout << "Derived method_2" << std::endl;
//  }

  int _a, _b;
};

int main()
{
  qDebug() << *QString().number(2).begin();
  Base* d = new Derived(1,2,3,4);
  //Derived* d = new Derived(1,2,3,4);
//  d->method_1();
//  d->method_2();

  delete d;


  return 0;
}
