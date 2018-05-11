//
//2つ入力して最大公約数を表示
//
//ユークリッドの互除法
//
//キーボードから入力せよ
//
#include<stdio.h>

//swap関数
void swap(int &num_1,int &num_2){

	int num_3;

	if(num_1 > num_2){
		num_1 = num_1;
		num_2 = num_2;
	}

	else{
		num_3 = num_1;
		num_1 = num_2;
		num_2 = num_3;
	}

	printf("%d>%dを確認\n",num_1,num_2);

}

//num_1のほうが大きいのを前提
//ユークリッド互除法
int  euclid(int num_1,int num_2){

	int num_3;

	while(1){
		num_3 = num_1 % num_2;

		if(num_3 == 0) break;

		num_1 = num_2;
		num_2 = num_3;

	}

	return num_2;

}



int main(void){

	int num_1;
	int num_2;
	int ans;

	printf("2つの数の最大公約数を求める\n");
	printf("数字1を入力せよ:");
	scanf("%d",&num_1);
	printf("数字2を入力せよ:");
	scanf("%d",&num_2);
	if(num_1>0 && num_2>0){

		swap(num_1,num_2);
		ans = euclid(num_1,num_2);

		printf("%dが最大公約数\n",ans);

	}

	else printf("正の数を入力するように\n");

}

