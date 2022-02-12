#include <iostream>
#include <bitset>
#include <string>

using namespace std;

int main()
{
	int bin = 0b11;
	cout << bin << endl;
	string binary = string(std::bitset<8>(0b11).to_string());
	cout << binary << endl;
}
