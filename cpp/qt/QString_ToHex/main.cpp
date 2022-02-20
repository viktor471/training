#include <QCoreApplication>
#include <iostream>
#include <QDebug>
#include <iomanip>

int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);
  char *idata = new char[8]{'h', 'e', 'l', 'l', 'o'};

  QByteArray byteArr(idata, strlen(idata));
  for( int i = 0; i < strlen(idata) - 1; i++)
  {
    std::cout << "0x";
    std::cout << std::setbase(16)
              << std::hex
              << std::setfill('0')
              << std::setw(2)
              << (int)idata[i] << " ";
  }

  std::cout << std::endl;

  QString  c;
  QTextStream b(&c);

  std::cout << std::endl;

  for( int i = 0; i < byteArr.size(); i++)
  {
    b << hex <<  (int)byteArr[i] << " ";
  //  c << hex <<  (int)byteArr[i] << " ";
  }

  qDebug() << c;

  //printf("%02X\n", 'h');

  delete[] idata;
  return a.exec();

}
