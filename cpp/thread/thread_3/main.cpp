#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

int doWork(int a, int b)
{
    std::this_thread::sleep_for(chrono::milliseconds(6000));
    cout << "doWork " << std::this_thread::get_id() << endl;
    std::this_thread::sleep_for(chrono::milliseconds(6000));
    cout << "doWork " << std::this_thread::get_id() << endl;
    std::this_thread::sleep_for(chrono::milliseconds(6000));
    cout << "doWork " << std::this_thread::get_id() << endl;
    return a + b;
}
int doWork(int a)
{
    cout << a << endl;
    return a;
}

void getValue()
{
    int a;
    cout << "Please print some int value" << endl;
    cin >> a;
    cout << "a " << a << endl;
}
int main()
{
    int a;
    std::thread th(doWork, 3, 4);
    std::thread th2(getValue);

    cout << "aaaa" <<  a << endl;;
    th.join();
    th2.join();
    return 0;
}
