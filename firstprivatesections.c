#include<stdio.h>
#include<omp.h>
#define N       5
int main(){
int i;
int a[N],b[N],c[N],d[N],e[N],f[N];
/* some initialization */
for (i=0; i<N;i++){
a[i]=i*1;
b[i]=i+2;
}
i=1;
/*Fork a team of threads with each thread having a private i variable and shared variable a,b,c,chunk*/
omp_set_num_threads(4);
#pragma omp parallel shared(a,b,c,d)
{
#pragma omp sections firstprivate(i)

{

        printf("inside parallel region and inside section %d\n",i);
 #pragma omp section
 for (i;i<N;i++){
        c[i]=a[i]+b[i];
        printf("section 1 # working thread : %d | %d + %d = %d\n",omp_get_thread_num(),a[i],b[i],c[i]);
}

#pragma omp section
 for (i;i<N;i++){
        d[i]=a[i]*b[i];
        printf("section 2 # working thread : %d | %d + %d = %d\n",omp_get_thread_num(),a[i],b[i],d[i]);

}
}


printf("inside parallel region but outside section %d\n",i);

}
printf("outsie parallel region %d\n",i);
 return 0;
  }

