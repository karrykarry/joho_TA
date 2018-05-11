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
			printf("out\n");
			hantei = false;
			break;
		}

	}
return hantei;

}



int main(void){

	int num;
	bool hantei;

	printf("数字を入力せよ\n");
	scanf("%d",&num);

	hantei = sosu_hantei(num);

	if(hantei)printf("%dは素数\n",num);
	else printf("%dは素数ではない\n",num);

}
