#include <iostream>
#include <string>
#include <iomanip>

void log( const std::string &msg )
{
	std::cout << msg << std::endl;
}

template <typename T>
void log( const std::string &msg, const T& var )
{
	using namespace std;

	cout << setw(15) << left << msg
		  << ":"
		  << var
		  << std::endl;
}

template <typename T> 
struct Base {

	void f()
	{
		log("Base<T>::f");
	}
};

template <typename T> 
struct Derived : Base<T> {
	
	void g() 
	{
		log("Derived<T>::g");
		f();
	}
};

void main() {}
