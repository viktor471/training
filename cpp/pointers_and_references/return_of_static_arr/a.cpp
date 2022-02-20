#include <iostream>


class Element
{
	int stored_var;

public:

	Element(){

		stored_var = 0;
		static int counter_constructor = 0;

		std::cout << "Element constructor " 
					 << "counter standard constructor " << counter_constructor++ 
					 << std::endl;
	
	}

	Element( int for_initialize_iner_member ){

		stored_var = for_initialize_iner_member;

		static int counter_constructor  = 0;
		
		std::cout << "Element constructor " 
					 << "counter constructor with arg " << counter_constructor 
					 << "internal val: "                << stored_var 
					 << std::endl;
	
	}

	~Element()
	{
		static int counter_destructor = 0;

		std::cout << "Element destructor "   
					 << "internal val: "     <<  stored_var 
					 << std::endl;
	}

	friend std::ostream& operator<< ( std::ostream&  cout_stream, 
												 Element 		 object      )
	{
		cout_stream << object.stored_var;
		return cout_stream;
	}

	int get_value_of_stored_var() const
	{
		return stored_var;
	}

	int change_stored_var( int new_value_of_stored_var )
	{
		return stored_var = new_value_of_stored_var;
	}

	int operator=( int new_value_of_stored_member )
	{
		return stored_var = new_value_of_stored_member;
	}
};


Element* creation_arr_of_elements( int size )
{
	Element arr_of_elements[ size ];

	for ( int i = 0; i < size; i++ )
	{
		arr_of_elements[i] = i;
	}

	return arr_of_elements;

}

int main(){

	Element* arr = creation_arr_of_elements( 10 );	
	std::cout << "after function call" << std::endl; 
   for ( int i = 0 ; i < 10; i++ )
		std::cout << arr[i] << std::endl;
}
