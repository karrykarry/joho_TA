//
//配列の各要素を図6_1に示す7人のテストの点数で初期化して，得点の高い順に並べる．
//さらに実行例のような分布グラフを出力する．
//

#include <stdio.h>

const int N = 7;
const int M = 10;

void sort(int *score){

	int tmp;

	for(int i=0;i<N-1;i++){
		for(int j=i+1;j<N;j++){
			if(score[i] < score[j]){
				tmp = score[i];
				score[i] = score[j];
				score[j] = tmp;
			}
		}
		printf("%3d", score[i]);
	}
	printf("\n");

}

void output(int *score){
	int rank[M] = {0};
	
	
	for(int i=0;i<N;i++){
		rank[score[i]/10]++;
	}
	
	for(int i=M-1;i>0;i--){
		if(i==M-1){
			printf("%3d〜%3d:", 10*i, 10*(i+1));
			for(int j=0;j<rank[i];j++){
			printf("*");
			}
			printf("\n");
		}
		else if(M-5<i&&i<M-1){
			printf("%3d〜%3d:", 10*i, 10*i+9);
			for(int j=0;j<rank[i];j++){
				printf("*");
			}
			printf("\n");
		}
		else{
			printf("%3d〜%3d:", 0, 10*i+9);
			for(int k=M-5;k>0;k--){
				for(int j=0;j<rank[k];j++){
					printf("*");
				}
			}
			printf("\n");
			break;
		}
	}

}

int main(void)
{
	int score[N] = {41, 30, 91, 85, 28, 66, 47};
	
	printf("得点の高い順\n");
	sort(score);
	printf("\n");
	printf("分布グラフ\n");
	output(score);
}

