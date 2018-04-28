//
//3つの整数値を読み込んでその最大値をもとめよ
//

#include<stdio.h>

int main(void){

	int num_1,num_2,num_3;
	int max;


	printf("整数1を入力してください:");
	scanf("%d",&num_1);

	printf("整数2を入力してください:");
	scanf("%d",&num_2);

	printf("整数3を入力してください:");
	scanf("%d",&num_3);

	max = num_1; 

	if(num_2 > max) max = num_2;

	if(num_3 > max) max = num_3;

	printf("最大値は%dです\n",max);

	return(0);

}
