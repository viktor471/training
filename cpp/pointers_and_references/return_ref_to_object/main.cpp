#include <iostream>

class A{

public:

int _i;

  A( int i, std::string msg ) :
  _i(i)
  {
    std::cout << "constructor A "
              << msg
              << std::endl
              << std::endl;
  }

  A( const A& another) : _i( another._i )
  {
    std::cout << "copy constructor A " << std::endl << std::endl;
  }

  ~A()
  {
    std::cout << "destructor A "       << std::endl << std::endl;
  }

  int& getter()
  {
    return _i;
  }
};

class B
{
  public:

  B()             { std::cout << "constructor B "       <<  std::endl  <<  std::endl; }

  B( const B& b ) { std::cout << "copy constructor B "  <<  std::endl  <<  std::endl; }
};

class Wrapper
{
  private:
    B _b;
    A _inherent_object;
  public:

  Wrapper( const A& tempor, const B& b ) : _b(b), _inherent_object(tempor )
  {
    std::cout << "&_inherent_object: "
              << &_inherent_object
              << std::endl
              << std::endl;
  }

  A& getter() { return _inherent_object; }

};

int main()
{
  B b;
  A ex_a_1(33, "main" );
  Wrapper ex_wrapper( ex_a_1, b );

  std::cout << "&ex_a_1: "
            <<  &ex_a_1
            << std::endl
            << std::endl;

  std::cout << "before assignment " << std::endl << std::endl;

  A &ex_a_2 = ex_wrapper.getter();

  std::cout << "&ex_a_2: "
            <<  &ex_a_2
            << std::endl
            << std::endl;

  return 0;
}
