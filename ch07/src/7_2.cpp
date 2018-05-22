//
//s—ñA=[[1, 2, 3], [4, 5, 6], [7, 8, 9]]‚Æs—ñB=[[9, 6, 3], [8, 5, 2], [7, 4, 1]]‚Ì
//“àÏ‚ğ‹‚ß‚éD
//

#include <stdio.h>

int main(void)
{
	const int N = 3;
	int mat_A[N][N] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
	int mat_B[N][N] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
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