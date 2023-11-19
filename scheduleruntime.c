#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

int main(int argc, char * argv[])
{
        omp_set_num_threads(4);

printf("with no chunksize passed:\n");
#pragma omp parallel for schedule(runtime)
for(int i=0;i<10;i++)
{
        printf("Thread %d processes iteration %d.\n",omp_get_thread_num(),i);
}

return 0;
}

