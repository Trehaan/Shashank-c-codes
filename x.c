// int* arr = malloc(sizeof(int)*5);
// int* arr = calloc(5,sizeof(int));

// int* arr = realloc(arr,sizeof(int)*10);

// free(arr);
#include<stdio.h>
#include<stdlib.h>

int* fun()
{
	int* arr = malloc(sizeof(int)*2);
	arr[0] = 5;
	return arr;
}

int main()
{
	int* arr = fun();
	printf("%d",arr[1]);
}