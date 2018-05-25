//
//2*2行列の各要素を入力して，その逆行列を求める．
//また，内積を計算して単位行列になることを確かめる．
//

#include <stdio.h>

const int N = 2;

void input(float mat[][N]){

	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			printf("mat_(%d, %d) = ", i, j);
			scanf("%f", &mat[i][j]);
		}
	}
	printf("\n");
}

void output(float mat[][N]){

	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			printf("%6.3f ", mat[i][j]);
		}
		printf("\n");
	}
}

float determinant(float mat[][N], float mat_det[][N]){

	float det;

	det = mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0];

	if(det==0){
		printf("正則ではありません\n");
	}
	else{
		mat_det[0][0] = mat[1][1]/det;
		mat_det[0][1] = -mat[0][1]/det;
		mat_det[1][0] = -mat[1][0]/det;
		mat_det[1][1] = mat[0][0]/det;

		printf("mat^-1 =\n");
	}

	output(mat_det);
	printf("\n");

	return det;
}

void identity(float mat[N][N],float mat_dev[N][N]){

	//初期化
	float mat_I[N][N] = {{0,0}
		,{0,0}};

	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			for(int k=0;k<N;k++){
				mat_I[i][j] += mat[i][k] * mat_dev[k][j];
			}
			printf("%6.3f ", mat_I[i][j]);
		}
		printf("\n");
	}
}



int main(void)
{
	float mat[N][N];
	float mat_dev[N][N];
	float det;

	printf("mat:\n");
	input(mat);

	printf("mat = \n");
	output(mat);

	printf("\n");

	det = determinant(mat,mat_dev);

	if(det!=0){
		printf("mat * mat^-1 =\n");
		identity(mat,mat_dev);
	}
}

