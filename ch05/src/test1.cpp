//
//入力した数までの素数を表示
//
//キーボードから入力せよ
//
#include<stdio.h>

bool sosu_hantei(int num){

	bool hantei = true;

	for(int i=2;i<num;i++){
		if(num%i == 0){
			hantei = false;
			break;
		}

	}

	return hantei;

}



int main(void){

	int num;
	bool hantei;

	printf("素数判定をしたい\n");
	printf("数字を入力せよ:");
	scanf("%d",&num);
	if(num>0){

		hantei = sosu_hantei(num);

		if(hantei)printf("%dは素数\n",num);
		else printf("%dは素数ではない\n",num);
	}

	else printf("正の数を入力するように\n");


}
