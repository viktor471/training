#include <iostream>
class cl
{
public:
  int a;
  cl() {};
  cl(int b){
      new(this) cl(b);
  }
};

using namespace std;

int main()
{
  cl u;
  cout << &u << std::endl;

  cout << "Hello World!" << endl;
  return 0;
}
