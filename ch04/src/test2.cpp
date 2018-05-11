//
//整数値を入力して,1からその数値までの和を求める
//

#include<stdio.h>

int main(void){

	int num;
	int sum = 0;


	printf("整数を入力してください:");
	scanf("%d",&num);

	for(int i=0;i<=num;i++){

		sum += i; 
	}

	printf("1から%dまで足した値は%dです\n",num,sum);

	return(0);

}

