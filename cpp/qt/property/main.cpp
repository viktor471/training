#include <iostream>

#include <QCoreApplication>
#include <QVariant>
//#include <QLabel>

class A : public QObject
{
  Q_OBJECT
  Q_PROPERTY(bool number READ number WRITE setNumber)

private:
  bool m_bNumber;

public:
  A( QObject* parent = 0) : QObject(parent), m_bNumber(true) {}
  ~A() {}

  int number() const { return m_bNumber; }
  void setNumber( bool number ) { m_bNumber = number; }

};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QMetaObject *b =
//    (&b)->setProperty()
  //  QLabel lab;
    //b.setProperty("number", 33);

 //   std::cout << b.number() << std::endl;

    //std::cout << b.property("number").toInt();
    return a.exec();
}
