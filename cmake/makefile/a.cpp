#include <iostream>
#include <function.h>
#include <string>
#include <string.h>
#include <QTextStream>

using namespace std;

int main(){
	string a="Hello";
	out(a);	
	QTextStream(stdout) << "Hello, world!" << endl;
	return 0;
}
