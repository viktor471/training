#include <QCoreApplication>
#include <iostream>

int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);

  std::cout << static_cast<qint64>(1E9) << std::endl;

  return a.exec();
}
