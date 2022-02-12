#include <QCoreApplication>
#include <iostream>

class FiboGenerator
{
    quint64 getNextFibo( int number )
    {
        if( first_time )
            if( number == 0 )
                return 1;
        else
            return number + getNextFibo( number );
    }

public:

    QList< int > generateSequenceUntilNumber( int number );
    QList< int > generateSequenceUntilIteration( int number );

    void demonstrateSequence( QList< int > list )
    {
        foreach( const int &element, list )
        {
            std::cout << element << " " << std::endl;
        }
    }

};

int main(int argc, char *argv[])
{
    FiboGenerator fibo_ex;
    QList< int > fibo_until_number = fibo_ex.generateSequenceUntilNumber( 100 );
    fibo_ex.demonstrateSequence( fibo_until_number );

    return 0;
}

QList<int> FiboGenerator::generateSequenceUntilNumber( int number )
{
    QList< int > list_of_numbers;
    int current_number = 0;
    list_of_numbers.append( 0 );
    while( number > current_number )
    {
        current_number = getNextFibo( current_number );
        list_of_numbers.append( current_number );
    }
    return list_of_numbers;
}
