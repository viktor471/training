#include <iostream>

int main(){
	int arr2[3][3];
	int (*arr)[3] = reinterpret_cast<int (*)[3]>( new( int[3]) );
	std::cout << "typeid.

}
