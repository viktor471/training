#include <QCoreApplication>
#include <iostream>
#include <QDebug>
#include <thread>
#include <list>

class Test
{
public:
    static void func()
    {
        std::cout << "hello from static in the class" << std::endl;
    }

};
    static void func()
    {
        std::cout << "hello from static member func" << std::endl;
    }

    static void func( int var_1 )
    {
        std::cout << "hello " << var_1 << std::endl;
    }

//    static void func( double var_1 )
//    {
//        std::cout << "hello " << var_1 << std::endl;
//    }

//    template< typename type >
//    void func( type var_1, type var_2 )
//    {
//        qDebug() << var_1 << " " << var_2;
//    }
//};

//void func()
//{
//    std::cout << "hello" << std::endl;
//}
template<typename Type>
void func2( Type var )
{
    std::cout << var << std::endl;
}


using fptr = void (*)(int) ;

int main()
{
    std::list< std::thread > threads;
        threads.push_back(std::thread( ( void (*)(void) )func));
        threads.push_back( std::thread( func2<int>, 3 ) );
        threads.push_back( std::thread( ( void (*)(int) )func, 3 ) );

        threads.push_back( std::thread( ( fptr )func, 3 ) );
        threads.push_back( std::thread( Test::func ) );
//        void (*funct)() =  &Test::func;
//        threads.push_back(std::thread(funct));
//        threads.push_back( func, 2.5 )
    for(auto& thr: threads) {
        thr.join();
    }
    return 0;
}
