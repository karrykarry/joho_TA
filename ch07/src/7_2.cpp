//
//行列A=[[1, 2, 3], [4, 5, 6], [7, 8, 9]]と行列B=[[9, 6, 3], [8, 5, 2], [7, 4, 1]]の
//内積を求める．
//

#include <stdio.h>

const int N = 3;

void inner(int  mat_A[][N],int mat_B[][N]){

	int mat_C[N][N];
	
	for(int m=0;m<N;m++){
		for(int n=0;n<N;n++){
			mat_C[m][n] = 0;
		}
	}
	
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			for(int k=0;k<N;k++){
				mat_C[i][j] += mat_A[i][k] * mat_B[k][j];
			}
			printf("%4d", mat_C[i][j]);
		}
		printf("\n");
	}

}


int main(void)
{
	int mat_A[N][N] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
	int mat_B[N][N] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};

	inner(mat_A,mat_B);

}


