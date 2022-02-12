#include <iostream>
#include <sigc++/signal.h>
#include <chrono>
#include <thread>
#include <time.h>

void func( const int a )
{
   int arr[a];
   for(int i = 0; i < a; i++ )
   {
       arr[i] = i;

       std::cout << arr[i] << " " << std::endl;
   }
}
int main()
{
    sigc::signal<void> sign;
    sign.connect( []{
        std::cout << "hello! " << std::endl;
    });
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    sign.emit();
    srand( time(0));
    func( rand()%48 );
    return 0;
}
