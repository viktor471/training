#include <iostream>
#include <QBitArray>
#include <QDebug>
#include <iomanip>

int main()
{
  int a = 258;
  QByteArray arr(reinterpret_cast< char* >(&a), sizeof(int));
  qDebug() << arr[0] << arr[1] << arr[2] << arr[3];

  char *carr = reinterpret_cast< char * >( &a );

  for( unsigned long i = 0; i < sizeof(int); i++ )
    std::cerr << std::hex << std::setfill('0') << std::setw(2)
              << static_cast<int>(carr[i])     << " ";

  int data_size = (carr[0] << 8) | carr[1];

  carr = reinterpret_cast< char *>( &data_size );

  std::cerr << std::endl << std::endl;

  for( unsigned long i = 0; i < sizeof(int); i++ )
    std::cerr << std::hex << std::setfill('0') << std::setw(2)
              << static_cast<int>(carr[i])     << " ";
  return 0;
}
