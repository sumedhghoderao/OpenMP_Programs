#include<stdio.h>
#include<omp.h>
int main()
{
int a[100];
int n;
int sum=0;
printf("Enter the number array elements\n");
scanf("%d",&n);


printf("Enter the array elements\n");
for(int i=1;i<n;i++)
{
        scanf("%d\n",&a[i]);
}

omp_set_num_threads(2);

#pragma omp parallel for reduction(+:sum)
for(int i=1;i<n;i++)
{
	sum=sum+a[i];
	printf("thread=%d sum=%d \n",omp_get_thread_num(),sum);


}

printf("sum=%d \n",sum);
return 0;
}
