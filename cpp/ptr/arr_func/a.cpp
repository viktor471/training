#include <iostream>

using std::cout;
using std::endl;

void func(int arr[], int size)
{
//	cout << sizeof(arr) << endl;
	for(int i = 0;  size > i ; i++) arr[i]++;
}
int main()
{

	int arr[7] = {1,2,3,4,5,6,7};

	func(arr , sizeof(arr));

	for(int i = 0; i < 7; i++) cout << arr[i] << " ";
   cout << endl;
}
