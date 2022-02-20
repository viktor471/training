#include <QCoreApplication>
#include <unistd.h>

int main(int argc, char *argv[])
{
  write( STDOUT_FILENO, "hello\n", sizeof("hello\n"));
  return 0;
}
