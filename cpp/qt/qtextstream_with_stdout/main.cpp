#include <QCoreApplication>
#include <QTextStream>

int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);
  QTextStream stream(stdout);

  stream << "hello\n";
  stream.flush();
  return a.exec();
}
