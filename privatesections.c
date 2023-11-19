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
/*Fork a team of threads with each thread having a private i variable and shared variable a,b,c,chunk*/
omp_set_num_threads(1);
#pragma omp parallel shared(a,b,c,d) private(i)
{
#pragma omp sections

{
 #pragma omp section
 for (i=0;i<N;i++){
        c[i]=a[i]+b[i];
        printf("section 1 # working thread : %d | %d + %d = %d\n",omp_get_thread_num(),a[i],b[i],c[i]);
}

#pragma omp section
 for (i=0;i<N;i++){
        d[i]=a[i]*b[i];
        printf("section 2 # working thread : %d | %d + %d = %d\n",omp_get_thread_num(),a[i],b[i],d[i]);

}
}



}
 //end of sections
 //end of parallel section


return 0;
}
