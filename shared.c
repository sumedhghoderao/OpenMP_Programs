#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
int main(int arg, char* argv[])
{
	int val = 0;
	int val1 =4;	
	#pragma omp parallel default(shared)
	{
		if(omp_get_thread_num() == 0)
		{
			printf("Thread 0 set the value of \"val\" to 123.\n");
			val = 123;
			val1 = 100;		
		}
	#pragma omp barrier
		if(omp_get_thread_num() == 1)
		{
			printf("Thread 1 reads the value of \"val\": %d.\n",val);
		}
	}

	#pragma omp parallel shared(val1)
        {
                if(omp_get_thread_num() == 0)
                {
                        printf("Thread 0 set the value of \"val\" to 123.\n");
                        

                }
        #pragma omp barrier
                if(omp_get_thread_num() == 1)
                {
                        printf("Thread 1 reads the value of \"val\": %d.\n",val1);
                }
        }

	
	return 0;
}
