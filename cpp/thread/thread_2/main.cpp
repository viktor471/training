#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>
#include <functional>
//#include <pthread>

using namespace std;

void doWork()
{
	using namespace std;
    cout << "this thread: " << std::this_thread::get_id() << endl;
    int k[10] = {1,2,3,4,5,6,7,8,9,10};
    //foreach(int i, k) cout << i << endl;
    for(int i = 0; i < 10; i++)
    {
        cout << this_thread::get_id() << endl;
        std::this_thread::sleep_for(chrono::milliseconds(1000));
        cout << "i'm awake " << i << " " << "doWork" << endl;;
    }
}

int main()
{
    std::thread my_thread(doWork);
    std::thread thread2(doWork);
    cout << "this thread: " << std::this_thread::get_id() << endl;
    int k[10] = {1,2,3,4,5,6,7,8,9,10};
    //foreach(int i, k) cout << i << endl;
    for(int i = 0; i < 10; i++)
    {
        std::this_thread::sleep_for(chrono::milliseconds(1000));
        cout << this_thread::get_id() << endl;
        cout << "i'm awake " << i << " " << "main" << endl;;
    }
    my_thread.join();
    thread2.join();
    return 0;
}
