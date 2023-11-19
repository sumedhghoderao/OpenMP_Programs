#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

int main()
 {
omp_set_num_threads(4);
int val=1234;
printf("value of \"val\" before the openmp parallel region %d.\n",val);
#pragma omp parallel firstprivate(val)
{
        printf("thread %d sees \"val\"=%d.\n",omp_get_thread_num(),val);
        //val = omp_get_thread_num();
        val++;
        printf("thread %d sees \"val\"=%d.\n",omp_get_thread_num(),val);
}

printf("value of \"val\" after the openmp parallel region: %d.\n",val);
return 0;
}
