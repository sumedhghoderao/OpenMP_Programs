#include<stdio.h>

int main()
{
	#pragma omp parallel
{
	#pragma omp task
	printf("hello world\n");
}
return 0;
}
