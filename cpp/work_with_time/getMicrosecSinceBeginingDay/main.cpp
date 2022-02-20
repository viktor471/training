#include <iostream>
#include <thread>

int main()
{
    struct timespec tm;
    for(int i = 0; i < 1000 ; i++)
    {
        clock_gettime(CLOCK_REALTIME, &tm);
        std::cout << (tm.tv_sec%(24*60*60))*1000 + (tm.tv_nsec/1000000) << std::endl;
        std::this_thread::sleep_for(std::chrono::microseconds(10000));
    }

    return 0;
}
