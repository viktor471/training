#include <iostream>

class my_class{
 public:
int a;
  my_class(){
    a = 5;
  }
};

using namespace std;

int main()
{

  my_class *ex = (my_class*)malloc( sizeof(my_class) );

  std::cout << ex->a << std::endl;
  cout << "Hello World!" << endl;
  return 0;
}
