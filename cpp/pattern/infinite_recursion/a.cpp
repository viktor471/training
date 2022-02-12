#include <iostream>

void rec_func( int n ){
	std::cout << "n: " << n << std::endl;
	rec_func( ++n );
}

int main(){
	unsigned long long recursion_number = 0;

	rec_func( recursion_number );

}
