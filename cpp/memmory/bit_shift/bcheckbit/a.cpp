#include <iostream>

using namespace std;

int main(int argc, char **argv){
	if(argc == 1) cout << "Arguments are needed" << endl;
	if(argc == 2)
	{
			  int arg1 = atoi(argv[1]);
			  cout << "arg1: " << arg1 << endl;
			  cout << "arg1 >> 0 = " << "("<<arg1<<" >> 0) = " << (arg1 >> 0) << endl;
			  cout << "((arg1 >> 0)&1)" << ((arg1 >> 0)&1) << endl;
	}
	if(argc == 3)
	{
			  int arg1 = atoi(argv[1]);
			  int arg2 = atoi(argv[2]);
			  cout << "arg1: " << arg1 << endl;
			  cout << "arg2: " << arg2 << endl;
		   	cout << "arg1 >> arg2 = " << "("<<arg1<<" >> "<<arg2<<") = " << (arg1>>arg2) << endl;
			  cout << "((arg1 >> arg2)&1) = " << "(("<<arg1<<" >> "<<arg2<<")&1) = " << ((arg1>>arg2)&1) << endl;
	}
}
