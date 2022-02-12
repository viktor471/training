#include "thread.hpp"
#include <signal.h>

void func( int signum )
{
    for( int i = 0 ; i < 1000; i++ )
    std::cout << "signum: "
              << signum
              << SIGSTOP
              << std::endl;
}

int main()
{
    signal(SIGSTOP, SIG_IGN );
    Thread th_1( new Concrete_1, true );

    Concrete_2* concrete_2( new Concrete_2 );

    concrete_2->set_other_thread( &th_1 );

    Thread th_2( concrete_2, true );

    th_1.run();
    th_2.run();

    //th_1.join();
    th_2.join();
}
