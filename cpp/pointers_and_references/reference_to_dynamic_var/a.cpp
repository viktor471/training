#include <iostream>

int main()
{
	int *com_int_var = new int(9);

	int &ref = *com_int_var;

	std::cout << "ref " << ref << std::endl;

	std::cout << "ref = 100" << std::endl;

	ref = 100;

	std::cout << "ref: " 			<< ref 			 << std::endl;
	std::cout << "*com_int_var: " << *com_int_var << std::endl;

}
