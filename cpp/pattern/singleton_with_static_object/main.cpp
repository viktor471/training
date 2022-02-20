#include <QCoreApplication>
#include <iostream>

class Test
{
  static Test _object;

  Test( QString str ) : _str( str )
  {
    std::cout << "constructor" << std::endl;
  }

  ~Test()
  {
    std::cout << "dctor" << std::endl;
  }

public:
  QString _str;
  static Test* get_instance()
  {
    return &_object;
  }

  static Test& get_instance2();
};

Test Test::_object = Test("hello");

int main(int argc, char *argv[])
{
  Test& object = Test::get_instance2();

  std::cout << object._str.toStdString().c_str() << std::endl;
  return 0;
}
