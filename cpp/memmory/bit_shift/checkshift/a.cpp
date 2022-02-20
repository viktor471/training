#include <iostream>

using namespace std;

int main(int argc, char **argv){
	
	int arg1 = 0;
	int arg2 = 0;
	int dir = 0;
	
	if(argc == 1)
	{
		cout << "Number?"    << endl;
		cin  >> arg1;
		cout << "direction?" << endl;
		cout << "to left: 1" << endl  <<  "to right: 2" << endl;
		while( dir != 1 && dir != 2 )
		{
			cin  >> dir;
			if(dir != 1 && dir != 2) cout << "out of range\n";
		}
		cout <<  ((dir == 1) ? "<<\n" : ">>\n") ;
		cout << "Number2?"   << endl;
		cin >> arg2;
		cout << "arg1: " << arg1 << " arg2: " << arg2 << endl;
		cout << "(arg1"   << ((dir == 1) ? " << " : " >> ") << "arg2) = (" 
			  << arg1     << ((dir == 1) ? " << " : " >> ") << arg2 << ") = "
			  << ((dir == 1) ? (arg1 << arg2) : (arg1 >> arg2))   << endl; 
	}
	if(argc == 2)
	{
			  int arg1 = atoi(argv[1]);
			  cout << "arg1: " << arg1 << endl;
			  cout << "(arg1 >> 0) = " << "("<<arg1<<" >> 0) = " << (arg1 >> 0) << endl;
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
	if(argc == 4)
	{

	}
}
