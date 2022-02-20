#include <iostream>
#include <string>

void print( std::string msg ) { std::cout << msg << std::endl; }

class A
{
public:
	int _member_A;
	A( int value ) : _member_A(value)  { }

	virtual ~A() { }
};

class B : public A
{
public:
	int _member_B;
	B( int member_B, int member_A ) : _member_B( member_B ), A( member_A ) { }

	~B() { }

	operator A() { 
		print("conversion operator B");
		return A(_member_B); }
};

class C
{
public:
	int _member_C;
	C( int member_C ) : _member_C( member_C ){ }

	~C(){ }

	operator A() { 
		print("conversion operator C");
		return A(_member_C);
	}
};


int main()
{

	class B b_1(2,3);

	std::cout << "class B b_1(2,3)" << std::endl << std::endl;

	std::cout << "B( int member_B, int member_A ) :"
		          " _member_B( member_B ), A( member_A )"  << std::endl
					 														<< std::endl;

	class A a_1(55);

	std::cout << "a_1._member_A before conv " << a_1._member_A << std::endl;
	
	a_1 = b_1;

	std::cout << "a_1._member_A after  conv " << a_1._member_A << std::endl;
	
	std::cout << std::endl;


	class C c_1(4);

	std::cout << "class C c_1(4);" << std::endl << std::endl;
	
	class A a_2(66); 

	std::cout << "a_2._member_A before conv " << a_2._member_A << std::endl;

	a_2 = c_1;
	
	std::cout << "a_2._member_A after  conv " << a_2._member_A << std::endl;

}

