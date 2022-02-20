#include <QCoreApplication>
#include <iostream>

int main(int argc, char *argv[])
{
  quint64 i = 0;
  QCoreApplication a(argc, argv);
  for( ; ; )
    std::cout << i++ << std::endl;
  return a.exec();
}
