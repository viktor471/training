#include <iostream>

using namespace std;

int main()
{

	unsigned long long delta_recv_send = (1599653246117364281 - 1599653246117228032);
	unsigned long long delta_proc_recv = (1599653246117393920 - 1599653246117364281);

	double miss = (double)delta_proc_recv/delta_recv_send;
	
	cout << "miss " << miss << endl;
}
