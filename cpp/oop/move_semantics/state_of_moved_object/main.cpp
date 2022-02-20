#include <iostream>

class A
{

  class Test
  {
  private:
    bool _state;
  public:

     Test( bool state = true ) : _state(true) {}
    ~Test() { turn_off(); }

    void turn_off() { _state = false; }
    bool state()    { return _state;  }

  };


public:
  Test        _test;
  std::string _msg = "hello";
  int         _var = 99;

  A() : _test(true)
  { std::cout << "default constructor" << std::endl; }

  ~A()
  {
    if( state() )
    {
      _test.turn_off();
      std::cout << "i'm ok" << std::endl;
    }
    else
      std::cout << "my data was stolen destructor" << std::endl;
    return;
  }

  A( const A&  another ) : _test(true)
  {
    std::cout << "copy constructor" << std::endl;
  }

  A(       A&& another ) :
    _test( true         ),
    _msg ( another._msg ),
    _var ( another._var )

  {
    std::cout << "move constructor" << std::endl;
    another._msg = "data was stolen";
    another._test.turn_off();
    another._var = 0;
  }

  A& operator=( const A&  another )
  {
    std::cout << "copy assignment" << std::endl;

    if(this == &another )
     return *this;

    _msg = another._msg;
    _var = another._var;

    return *this;
  }

  A& operator=(       A&& another )
  {
    std::cout << "move assignment" << std::endl;

    if( this == &another )
      return *this;

    _msg = another._msg;
    _var = another._var;

    another._msg = "";
    another._var = 0;
    another._test.turn_off();

    return *this;
  }

  bool state() { return _test.state(); }
};

int main()
{

//  A ex_1;

//  std::cout << ex_1._msg << std::endl;
//  std::cout << std::boolalpha << ex_1.state() << std::endl;
//  std::cout << ex_1._var << std::endl;
//  A ex_2 = std::move(ex_1);

//  std::cout << ex_1._msg << std::endl;
//  std::cout << std::boolalpha << ex_1.state() << std::endl;
//  std::cout << ex_1._var << std::endl;

//A ex_3;
//  std::move(ex_3);

//  std::cout << ex_3._msg << std::endl;
//  std::cout << std::boolalpha << ex_3.state() << std::endl;
//  std::cout << ex_3._var << std::endl;

//  std::move(ex_3)._msg = "data was stolen";

//  std::cout << ex_3._msg << std::endl;


A ex_3;

//A &&ex_5 = A();
A &&ex_4 = std::move(ex_3);

ex_4._msg = "data was stolen";

std::cout << ex_3._msg << std::endl;

  return 0;
}
