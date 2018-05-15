//
//必ず答えが3になります
//

#include <stdio.h>
int function1(int num){
	int ans;
	printf("その数に1を足してください：");
	ans = num + 1;
	printf("%d\n", ans);

	return ans;
}

int function2(int num){
	int ans;
	printf("2倍にしてください：");
	ans = 2 * num;
	printf("%d\n", ans);

	return ans;
}

int function3(int num){
	int ans;
	printf("4を足してください：");
	ans = num + 4;
	printf("%d\n", ans);

	return ans;
}

int function4(int num){
	int ans;
	printf("2で割ってください：");
	ans = num / 2;
	printf("%d\n", ans);

	return ans;
}

int function5(int num, int num0){
	int ans;
	printf("最初に思い浮かべた数を引いてください：");
	ans = num - num0;
	printf("%d-%d\n",num ,num0);

	return ans;
}

int main(void){
	int num1, num2, num3, num4, num5, num6;

	printf("整数を入力してください：");
	scanf("%d", &num1);

	num2 = function1(num1);
	num3 = function2(num2);
	num4 = function3(num3);
	num5 = function4(num4);
	num6 = function5(num5, num1);

	printf("その数はずばり%dです\n", num6);
}
