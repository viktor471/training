#include <QCoreApplication>
#include <QTextStream>
#include <QFile>

int main(int argc, char *argv[])
{
  QString string("hello");
  QFile file( "file");
  file.open( QIODevice::WriteOnly );
  QTextStream stream( &file );
  stream << string;
  stream.flush();
  file.close();
  return 0;
}
