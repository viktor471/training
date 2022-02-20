#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "factorial.h"

int main(int argc, char **argv){
		  srand(time(0));
		  int arg;
		  if (argc > 1) arg = atoi( argv [1]);
		  else arg = rand()%10;
printf("arg: %d\n", arg);
printf("factorial: %d\n", factorial(arg));
}
