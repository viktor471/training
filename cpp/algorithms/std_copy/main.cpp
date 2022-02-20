#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  std::vector<int> vec;

  int arr[] = {7,8,9,1,2,3};

  int arr_size = sizeof(arr)/sizeof(int);
  vec.resize( arr_size );

  std::copy( arr, arr + arr_size, vec.begin() );

  for( int &value : vec )
    std::cout << " " << value;

  std::cout << std::endl;

  return 0;
}
