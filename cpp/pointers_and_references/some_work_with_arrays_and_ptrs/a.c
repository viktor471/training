#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

/*	int a = 9;
	char b = 'c';
	a++;
	a=a+2;
	printf("a: %d\n", a);
	printf("b: %c a: %d\n", b, a);
*/
/*
	// комментарий
	//
	int arr[5] = {1, 2, 4, 6, 7};
	
	int a = 0;
	float b = 2.5;
	printf("b %f \n", b);
	printf(" arr: %d %d %d %d %d \n", arr[0], arr[1], arr[2], arr[3], arr[4] );

	for( int i = 0; i < 10; i++)
	{
		a+=i;
		printf("i: %d a: %d \n", i, a); 
	}

	a = 1;
	b = 0;
	int c = 0;

	for( int i = 0; i < 100; i++ )
	{
		c = b;
		a = b + a;

	}

	int f = 2;
	int d = 6;

	for (int i = 4; i >  0; i-- )
	{
		a = ( (2 & ( 1 << i)) && 1);
		printf("%d ", a);
	}
	
*/

	int arr[10];

	srand(time(0));
	for (int i =0 ; i < 10; i++){
		arr[i] = rand()%100;
		printf(" arr[%d] : %d \n", i, arr[i]);
	}

	int *pointer = arr;
	
	for (int i =0 ; i < 10; i++ )
	{
		printf("%p arr[%d] %d \n", pointer++, i, arr[i]);
	}

	pointer = arr;
	
	printf("\n");

	for (int i = 0 ; i < 10; i++ )
	{
		printf("%p arr[%d] %d \n", pointer, i, pointer[i]);
	}

	int arr2[2][3] = { {2, 3, 4}, {5, 6, 7} };
	int *pointer4;
	pointer4 = arr2;
	for (int i = 0; i < 6; i++)
	{
		printf("%p pointer4[%d]: %d\n", &(pointer4[i]), i, pointer4[i] );
	}
	
	for (int i = 0; i < 2; i++)
	{
		for ( int k = 0; k < 3; k++){
			printf(" arr2[%d][%d]: %d \n", i, k, arr2[i][k]);
		}
	}
	
	printf(" addr: arr2[0] %p \n", arr2[0]);
	printf(" addr: arr2[1] %p \n", arr2[1]);
	printf(" addr: arr2 %p \n", arr2);

	int *pointer2 = (int*)malloc(sizeof(int)*3);	
	pointer2[0] = 3;
	pointer2[1] = 55;
	pointer2[2] = 66;

	printf ("poniter2[0]: %d \n", pointer2[0]);
	int **pointer3 = (int**)malloc(sizeof(int*)*2);
	pointer3[0] = pointer2;
	pointer3[1] = arr2[0];
	
	printf("pointer3: %p\n", pointer3);

	for( int i = 0; i < 2; i++)
	{
		printf("pointer3[%d]: %p \n", i, pointer3[i]);
		for(int k = 0; k < 3; k++)
		{
			printf(" %p pointer3[%d][%d]: %d \n", &(pointer3[i][k]), i, k, pointer3[i][k]);
		}
	}
	printf("pointer3: %p pointer2 %p\n");
	free(pointer2);
}
