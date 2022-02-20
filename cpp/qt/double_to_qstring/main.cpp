#include <QCoreApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
  double value = 3.5;
  QString str = QString().number( value );

  QString::
  str.replace('.', ',');
  qDebug() << str;
  return 0;
}
