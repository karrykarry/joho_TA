//
//入力した自然数以下の素数をすべて表示する
//

#include <stdio.h>

int main(void){
	int num;
	int i = 2;
	int judge = 0;

	printf("自然数を入力してください：");
	scanf("%d", &num);
	
	if(num<1){
		printf("エラー\n");
	}
	else{
		while(i<=num){
			int j = 2;
			while(j<i){
				if(i%j==0){
					judge = 1;
				}
				j++;
			}
			
			if(judge==0){
				printf("%d ", i);
			}
			i++;
			judge = 0;
		}
		printf("\n");
	}
}
