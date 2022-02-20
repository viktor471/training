#include <QCoreApplication>
#include <iostream>

int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);
  int x = 3;
  int y = 7;
  std::cerr << (x++)+(++y);
  return a.exec();
}
