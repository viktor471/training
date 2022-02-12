#include <vector>
#include <thread>
#include <iostream>
#include <algorithm>

typedef std::vector<std::thread> arr_thread;

int main()
{
    arr_thread worker;

    for(int i = 0; i < 10; i++ )
    {
        worker.push_back(std::thread([i](){
            std::cout << "hello from " << std::this_thread::get_id() << " " << i << "\n";
        }));
    }
    std::cout << "hi from main" << std::endl;

    std::for_each(worker.begin(), worker.end(), [](std::thread &th)
    {
       th.join();
    });

}
