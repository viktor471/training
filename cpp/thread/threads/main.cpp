#include <QCoreApplication>
#include <iostream>
#include <thread>

void func()
{
    for( int i = 0; i < 100; i++ )
        std::cout << "i: "
                  << i
                  << " id th: "
                  << std::this_thread::get_id()
                  << std::endl;
}

int main()
{
    std::thread th_1( func );
    std::thread th_2( func );

    th_1.join();
    th_2.join();

    return 0;
}
