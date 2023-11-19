#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
int main(int argc, char* argv[]){
               
//Use 4 threads when creating OPenmp parallel region
omp_set_num_threads(4);
int total = 0;
//create the parallel region               
#pragma omp parallel default(none) shared(total)
{
	for(int i=0; i<10; i++)
	{
        	//Atomatically add one to the total
       		#pragma omp atomic
		total++;
        }
                
}
printf("Total = %d..\n",total);

return 0;

}

