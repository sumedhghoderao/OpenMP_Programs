#include<stdio.h>
#include<omp.h>
static long num_staps = 4;
double step;
int main(){
	int i;
	double pi,x,sum = 0.0;
	step = 1.0/(double)num_staps;
	{
		double x;
		#pragma omp parallel for reduction(+:sum)
		for(i=0; i<num_staps; i++)
		{
			x = (i + 0.5) * step;
			sum = sum + 4.0/(1.0 + x * x);
		}
	}
	pi = step * sum;
	printf("%lf ",pi);
}
