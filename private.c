#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

int main()
 {
omp_set_num_threads(4);
int val=1234;
printf("value of \"val\" before the openmp parallel region %d.\n",val);
#pragma omp parallel private(val)
{
	printf("thread %d sees \"val\"=%d,and updates it to be %d.\n",omp_get_thread_num(),val,omp_get_thread_num());
	val = omp_get_thread_num();
}

printf("value of \"val\" after the openmp parallel region: %d.\n",val);
return 0;
}
