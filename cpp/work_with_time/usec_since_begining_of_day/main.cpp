#include <iostream>
#include <time.h>
#include <thread>

int main(int argc, char *argv[])
{
    struct timespec tm;
    //std::cout << tm.tv_sec%(24*60*60) << std::endl;
    //std::cout << tm.tv_nsec << std::endl;

    for(int i = 0; i < 1000; i++)
    {
      clock_gettime(CLOCK_REALTIME, &tm);
      std::cout << ((tm.tv_sec%(24*60*60))*1000 + (tm.tv_nsec/1000000)) << std::endl;
      std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
}
