#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <list>
#include <shared_mutex>

int main()
{
    std::mutex m;
    std::lock_guard < std::mutex >  lock1(m);
    std::unique_lock< std::mutex > lock2(m);
    std::shared_lock< std::mutex > lock3(m);

    return 0;
}
