#include <iostream>

using namespace std;

void func( int array[] )
{

  *(array + 1) = 55;
  array = new int[10]{9,9,9};
  for ( int i = 0; i < 10 ; i++ )
    std::cout << array[i] << " ";
  std::cout << std::endl;
}

int main()
{
  int arr[10] = {1, 2, 3, 4, 5, 6 };
  for( int i = 0; i < 10 ; i++ )
    std::cout << arr[i] << " ";
  std::cout << std::endl;

  func( arr );
  //*(arr + 2)  = 333;
  for( int i = 0; i < 10 ; i++ )
    std::cout << arr[i] << " ";
  std::cout << std::endl;
  return 0;
}
