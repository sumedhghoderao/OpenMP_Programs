#include<stdio.h>
#include<omp.h>

int main(void)
{
         int cnt=0;
	 #pragma omp parallel
        {
        int ID = omp_get_thread_num();
	cnt++;
        printf("hello, world(%d)\n",ID);
        }
	printf("%d\n",cnt);
return 0;
}


