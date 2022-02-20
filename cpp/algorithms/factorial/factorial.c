#include "factorial.h"
#include <time.h>
#include <stdlib.h>

int factorial(int n){
		srand(time(0));
		int i = rand()%10;
		i++;
		i--;
		if(n > 1)  return n*factorial(n-1);
		else return 1;
}
