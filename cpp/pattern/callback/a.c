#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* The calling function takes a single callback as a parameter. */
void printTwoNumbers( int (*numberSourc)(void))
{
	int val1 = numberSourc();
	int val2 = numberSourc();

	printf("%d and %d\n", val1, val2);
}

/* A possible callback */
int overNineThousand(void) { return (rand()%1000) + 9001; }

/* Another possible callback */
int meaningOfLife(void) { return 42; }

/* Here we call PrintTwoNumbers() with three different callbacks. */

int main(){
	time_t t;

	srand(  (unsigned)time( &t )  ); //Init seed for random function

	printTwoNumbers( &rand );

	printTwoNumbers( &overNineThousand );

	printTwoNumbers( &meaningOfLife );

}
