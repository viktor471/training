#include <QCoreApplication>
#include <iostream>

int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);
  double b = 2./3;
  std::cout << b << std::endl;
  return a.exec();
}
