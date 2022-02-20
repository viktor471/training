#include <memory>
#include <iostream>

class Example
{
  public:
  int _a, _b;
  Example( int a = 0, int b = 0) :
    _a(a), _b(b)
    {
      std::cerr << "constructor" << std::endl;
    }

  ~Example()
  {
    std::cerr << "destructor" << std::endl;
  }
};

int main()
{
  std::unique_ptr<int> ptr = std::make_unique<int>(9);

  std::cout << *ptr << std::endl;

  std::unique_ptr< Example > ex( new Example(99,88) );

  std::cout << " a: " << ex->_a
            << " b: " << ex->_b
            << std::endl;

//  std::unique_ptr< Example > ex2( ex.get() );

  Example ex_3(0, 78);

  std::unique_ptr< Example > ex3( &ex_3 );

  std::cout << "ex1: "    << ex.get()  << std::endl;
//  std::cout << "ex2: "    << ex2.get() << std::endl;

  std::cout << "ex3->a: " << ex3->_a
            << "ex3->b: " << ex3->_b
            << std::endl;

  return 0;
}
