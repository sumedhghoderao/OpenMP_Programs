#include<stdio.h>
#include<omp.h>

int main()
{
	#pragma omp parallel
 {
 	#pragma omp single
	{
	#pragma omp task
	{
	printf("task one running on thread %d\n",omp_get_thread_num());
        }
        #pragma omp task
	{
	printf("task two running on thread %d\n",omp_get_thread_num());
        }
	}
	}
	return 0;
	}

      
