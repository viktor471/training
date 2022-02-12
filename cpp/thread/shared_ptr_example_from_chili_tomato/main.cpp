#include <QCoreApplication>
#include <iostream>
#include <QTextStream>

class Base
{
protected:
  QTextStream _stream;

public:
  Base() : _stream( stdout ) {};
};

class Resource : public Base
{
  QString     _name;

public:

  Resource( QString name ) :
    Base (),
    _name( name   )
  {
    _stream << "Resource [" + _name + "] is alive!\n";
  }

  Resource( const Resource& other ) :
    Base (),
    _name( other._name )
  {
    _stream << "Resource [" + _name + "] is alive by copy!\n";
  }

};

int main()
{
  Resource("hello");

  return 0;
}
