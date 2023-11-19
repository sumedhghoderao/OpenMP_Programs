#include<stdio.h>
#include<unistd.h>
#include<omp.h>
int main(){
	int shared_variable = 0;

#pragma omp parallel num_threads(2)
{
       int thread_id = omp_get_thread_num();
       int private_variable = 0;  
       
	if(thread_id ==1)
        {
		// Thread 0 writes to the shared variable
        	private_variable=42;
                #pragma omp flush

		shared_variable=private_variable;
		#pragma omp flush(shared_variable)
        }
        else
        {
        //Thread 1 reads the shared variable
	#pragma omp flush(shared_variable)
	private_variable=shared_variable;
	#pragma omp flush
        }
printf("Thread %d: private_variable = %d, shared_variable = %d\n",thread_id, private_variable,shared_variable);
}
return 0;
}

