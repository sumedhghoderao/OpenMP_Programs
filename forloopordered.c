#include<stdio.h>
#include<omp.h>
#include<stdlib.h>
int main(int argc, char* argv[])
{
        
        omp_set_num_threads(4);
        #pragma omp parallel for ordered

        for(int i=0;i<10;i++)
        {
                printf("The thread %d value is %d\n",omp_get_thread_num(),i);
                
        }
        return 0;
}

