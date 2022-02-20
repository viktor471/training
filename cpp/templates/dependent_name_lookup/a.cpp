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
	typedef int MyType;

	static void f()
	{
		log("Base<T>::f");
	}
};

template<>
struct Base<int>{

	void f()
	{
		log("Base<int>::f");
	}
};

template <typename T> 
struct Derived_1 : Base<T> {
	typename Base<T>::MyType k = 2;	
	void g() 
	{
		log("Derived<T>::g");
		Derived_1<T>::f();
	}
};

template <typename T> 
struct Derived_2 : Base<T> {
	
	void g() 
	{
		log("Derived<T>::g");
		Base<T>::f();
	}
};

template <typename T> 
struct Derived_3 : Base<T> {
	
	void g() 
	{
		log("Derived<T>::g");
		this->f();
	}
};

int main() {

	Derived_1<int> der_1;
	Derived_2<int> der_2;
	Derived_3<int> der_3;

	der_1.g();
	der_2.g();
	der_3.g();
}
