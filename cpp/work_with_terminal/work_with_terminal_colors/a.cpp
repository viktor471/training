#include <iostream>
#include <string>
#include <iostream>
#include "color.h"

//TODO спрашивать, что хотите сделать. Вывести название программы.

using namespace std;

int main(){
	
	cout << "======== life questions - type h for help =======" << endl;
	string answer = "yes";
	Color::Modifier red(Color::FG_RED);
	Color::Modifier def(Color::FG_DEFAULT);
	Color::Modifier bold(Color::BOLD);
	Color::Modifier reset(Color::RESET);
	while ( answer != "q" )
	{
		cout << red << bold << "[" << def << " lq " << red << "] " << reset;	
		cin >> answer;
	}

}


