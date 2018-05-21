//
//16進数を入力後，対応する16進数と10進数
//
//キーボードから入力せよ
//
#include<stdio.h>

void print_num(int num){

	printf("10進数：%d\n",num);
	// printf("16進数：%x\n",num);

}


int main(void){

	int num;

	printf("16進数を入力せよ:");
	scanf("%x",&num);

	print_num(num);

}

