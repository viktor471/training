#include <iostream>
#include <thread>

using namespace std;

int main()
{

	std::thread th([](){
	 	cout << "hello from thread\n";
			});


	cout << "hello from main\n";
	th.join();

}
