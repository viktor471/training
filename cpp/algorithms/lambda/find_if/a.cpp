#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
#include <functional>

using namespace std;

typedef std::function<void(int)> lambda;

typedef vector<int> :: iterator (*find_alg)(vector<int>::iterator, vector<int>::iterator, lambda);
typedef vector<int> collect;
//vector<lambda> lambdas;
vector<std::function<void(int)>> lambdas;

//function to print vector
void printVector( vector<int> v );

void findFirstNumberGreaterThan4( vector<int> v, find_alg);

int main()
{

	vector<int> v {1,2,3,4,5};
	printVector(v);

    findFirstNumberGreaterThan4(v, find_if<collect, lambda>);
}


void findFirstNumberGreaterThan4( vector<int> v, find_alg)
{
    lambdas.push_back([](int i) -> int { return i > 4; });
	 
	 // below snippet find first number greater than 4 
    // find_if searches for an element for which 
    // function(third argument) returns true 
    vector<int> :: iterator p = callback_func(v.begin(), v.end(), lambdas.end());
	cout << endl << "first element greater than 4 is " << *p << endl;
}

void printVector( vector<int> v )
{
	for_each(v.begin(), v.end(), [](int i){ std::cout << i << " "; } ); 
}


