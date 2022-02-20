#include <iostream>

using namespace std;

void func( int (&arr)[3])
{
  std::cout << "func  "  << sizeof(arr) << std::endl;
}

void func2( int *arr[3])
{
  std::cout << "func2 " << sizeof( arr[1] ) << std::endl;
}

void func3( int (*arr)[3])
{
  std::cout << "func3 " << sizeof( arr[1] ) << std::endl;
}

void func4( int arr[3][3] )
{
  std::cout << "func4 " << sizeof( arr[1] ) << std::endl;
}

void func5( int *arr[3] )
{
  std::cout << "func5"            << std::endl
            << " sizeof(arr[1]) "  << sizeof( arr[1] )
            << " sizeof(arr[2]) "  << sizeof( arr[2] )
            << " sizeof(arr[3]) "  << sizeof( arr[3] )
            << std::endl;
}

void func6( int arr[3][3] )
{
  std::cout << "func5"            << std::endl
            << " sizeof(arr[1]) "  << sizeof( arr[1] )
            << " sizeof(arr[2]) "  << sizeof( arr[2] )
            << " sizeof(arr[3]) "  << sizeof( arr[3] )
            << std::endl;
}

int main()
{
  int arr[3];
  int *arr2[3] = { new int[4], arr, new int[1] };
  func( arr );
  int arr3[3][3];
  func2(arr2);

  func3(arr3);
  func4(arr3);
  func5( arr2 );
//  func6(arr2);
  cout << "Hello World!" << endl;
  return 0;
}
