#include <stdio.h>
#include <stdlib.h>
#include "f.h"
#include "f2.h"

int main(){
		  int i = f2();
		  int a = i;
		  int j = 2;
		  i++;
		  i = j + 2;
		  i = a;
		  i = f1();
		  printf("number: %d\n", i);
}
