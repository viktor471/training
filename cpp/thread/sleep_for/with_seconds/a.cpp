#include <iostream>
#include <chrono>
#include <thread>
 
int main()
{
    using namespace std::chrono_literals;
 
    std::cout << "Hello waiter\n" << std::flush;
 
    const auto start = std::chrono::high_resolution_clock::now();
    std::this_thread::sleep_for(2s);
    const auto end = std::chrono::high_resolution_clock::now();
    const auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    std::cout << "Waited " << elapsed << '\n';
}
