#include<stdio.h>
#include<omp.h>

int main(){
    int matrix1[3][3];
    int matrix2[3][3];
    int result[3][3];

printf("Enter matrix 1 values\n");
for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            scanf("%d", &matrix1[i][j]);
        }
	printf("\n");
    }


printf("Enter matrix 2 values\n");
for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            scanf("%d", &matrix2[i][j]);
        }
	printf("\n");
    }


for (int p = 0; p < 3; p++) {
        for (int q = 0; q < 3; q++) {
            result[p][q]=0;
}
	
}

#pragma omp parallel for

for( int p = 0; p < 3; p++) {
        for (int q = 0; q < 3; q++) 
        {
            for (int k = 0; k < 3; k++)
             {
                result[p][q] = result[p][q] + matrix1[p][k] * matrix2[k][q];
            }
        }
    } 

for (int p = 0; p < 3; p++) {
        for (int q = 0; q < 3; q++) {
            printf("%d\t", result[p][q]);
        }
        printf("\n");

    }
return 0;

}

