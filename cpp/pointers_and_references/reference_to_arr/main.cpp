#include <iostream>

using namespace std;


int main()
{

int arr[5] = {1,2,3,4,5};

int (*arr2)[5] = &arr;

  cout << *(arr + 2)     << std::endl;
  cout << "Hello World!" << endl;
  return 0;
}
