#include <QCoreApplication>
#include <iostream>

template < typename Type >
class Any_output
{

public:

    using ostream = std::ostream;

    Type _var;
    Any_output( Type var_ ) : _var( var_ ) {};

    friend ostream &operator<<( ostream &output, Any_output<Type> &object )
    {
        return output << "common class: " << object._var;
    }

};

template <>
class Any_output<int>
{

public:

    using ostream = std::ostream;

    int _var;
    Any_output( int var_ ) : _var( var_ ) {};

    friend ostream &operator<<( ostream &output, const Any_output<int> &object );

};

template < typename  T>
std::ostream &operator<<( std::ostream &output, const Any_output<T> &object )
{
   return output << "common class: " << object._var;
}

std::ostream &operator<< ( std::ostream &output, const Any_output<int> &object )
{
   return output << "int class: " << object._var;
}

template<>
std::ostream &operator<< <int> ( std::ostream &output, const Any_output<int> &object )
{
   return output << "int 2 class: " << object._var;
}

template< typename Type >
void func( Type var )
{
    std::cout << "common function: " << var << std::endl;
}

template<>
void func<int>( int var )
{
    std::cout << "int function: " << var << std::endl;
}

int main()
{

    func( Any_output<double>(2.6) );
    func( 3 );
    func( 2.4 );

    std::cout << Any_output<int>(2) << std::endl;

//    std::cout.operator<< <int> ( std::cout(, Any_output<int>(2) );

//    std::cout.operator<< <int> ( Any_output<int>(2));
    return 0;
}



















