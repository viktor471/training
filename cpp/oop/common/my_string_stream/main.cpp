#include <iostream>
#include <string>

class MyStringStream
{
private:
  std::string _content;
public:
  MyStringStream( std::string content="" ) : _content(content) {}
  MyStringStream( MyStringStream &stream ):
  _content(stream._content) {}

  template<typename T>
  friend MyStringStream &operator<< ( MyStringStream& stream, const T &value );

  std::string &str() { return _content; }
};

  template<typename T>
  MyStringStream &operator<< ( MyStringStream& stream, const T &value );


  template<>
  MyStringStream &operator<<( MyStringStream& stream, const int &value )
  {
    char buf[100];
    snprintf(buf, 100, "%d", value);
    stream._content += std::string(buf);
    return stream;
  }

  template<>
  MyStringStream &operator<<( MyStringStream& stream, const std::string &str )
  {
    stream._content += str;
    return stream;
  }

//  template<>
//  MyStringStream &operator<<( MyStringStream& stream, const char &str )
//  {
//    stream._content += str;
//    return stream;
//}

void test_func()
{
  MyStringStream stream;
  typedef std::string s;
  stream << s("hello ") << 2 << s(" and other string");

  std::cout << stream.str() << std::endl;
}

int main()
{
  test_func();
  return 0;
}
