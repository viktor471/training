#include <iostream>

using namespace std;

int main()
{
	char a;
	cout <<  "enter letter. q - for exit." <<  endl;
	//scanf("%c",  a);
	cin >> a;
	while(a != 'q')
	{
		cout << "\7" << endl;
		cout << "enter letter. q - for exit" <<  endl;
		//scanf("%c", a);
		cin >> a;
	}
}
