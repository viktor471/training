#include <QCoreApplication>
#include <iostream>
#include <signal.h>

typedef void (&func)(void);
typedef void (*func_ptr)(void);

void func2(void)
{
  std::cout << "hello" << std::endl;
}

int main(int argc, char *argv[])
{

  SIGFPE;

  func func3 = func2;
  func3();

  func_ptr func4  = func2;

  func4();
//  func3 = func2;

//  func func5 = func{ std::cout << "hello2" << std::endl; };
  QCoreApplication a(argc, argv);

  return a.exec();
}
