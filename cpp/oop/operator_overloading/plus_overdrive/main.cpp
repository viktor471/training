#include <iostream>

using namespace std;

class Int{
private:

  int content;
  std::string str;

  Int operator = ( int a )
  {
    content = a;
    return Int(a);
  }

  /*Int operator = ( Int & a)
  {
    content = a.
  }*/


public:

  Int ()
  {
    std::cout << "default constructor" << std::endl;
    content = 0;
  }

  ~Int() { std::cout << "destructor" << std::endl << std::endl; }
  Int( int cont )
  {
    content = cont;
    std::cout << "&content " << &content << " cont: " << cont << std::endl;

  }

  int getContent() {
    return content;
  }


  Int operator + ( Int b)
  {
    std::cout << "hello world" << std::endl;
    std::cout << std::endl << "operator +" << std::endl;
    return Int(content + b.getContent());
  }


  friend std::ostream &operator << (std::ostream &stream, Int ex )
  {
    stream << ex.content;
    return stream;
  }

};


int main()
{
  cout << "Int a" << std::endl;
  Int a = 5;

  cout << std::endl << "Int b" << std::endl;
  Int b = 5;

  cout << "a: " << a << std::endl;
  cout << "b: " << b << std::endl;

  cout << std::endl << "Int c" << std::endl;
  //a + b;
  Int c;
  cout << std::endl << "Int d" << std::endl;
  Int d(8);

  cout << "a + b " << a + b << std::endl;

  a + b;
  a + b;
  a + b;
  a + b;
  a + b;
  a + b;
  a + b;

  return 0;
}
