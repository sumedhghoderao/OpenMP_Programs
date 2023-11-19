#include<stdio.h>
#include<omp.h>
int main()
{
	# pragma omp parallel
{ 
       if(omp_in_parallel()){
	
        printf("Inside a parallel region\n");
        }
        else{
        printf("Not inside a parallel region\n");
        }

} 
       return 0;
}
