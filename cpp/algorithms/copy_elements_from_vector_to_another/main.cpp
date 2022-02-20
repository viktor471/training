#include <iostream>
#include <vector>
#include <string>
#include <QVector>

class Element
{
private:

  int _i;

public:

  Element(int i): _i(i)
  {
    std::cout << "ctor: " << _i << std::endl;
  }

  ~Element()
  {
    std::cout << "dctor: " << _i << std::endl;
  }
};

template <typename T>
class Vector : public QVector<T>
{
private:
  std::string _name;

public:
  Vector(const std::string& name) : _name(name)
  {
    std::cout << "ctor of vector: " << _name << std::endl;
  }

  ~Vector()
  {
    std::cout << "dctor of vector: " << _name << std::endl;
  }
  Vector(const Vector& vector) : QVector<T>(vector) {}

};

int main()
{
    std::cout << "before vector_1 ctor" << std::endl;

    Vector<int> vector_1("vector_1");

    std::cout << "creation of elements" << std::endl;
//    Element elements[5] = {Element(1), Element(2), Element(3), Element(4), Element(5)};
//    std::cout << "before push back" << std::endl;
//    for( int i = 0; i < 5; i++ )
//      vector_1.emplace_back(Element(i));
    for( int i = 0; i < 5; i++ )
      vector_1.push_back(i);

    std::cout << "before vector_2 ctor" << std::endl;

    Vector<int> vector_2("vector_2");

    std::cout << "before copying" << std::endl;

    vector_1 = vector_2;

    std::cout << "after copying" << std::endl;

    std::cout << "end of program" << std::endl;

    return 0;
}
