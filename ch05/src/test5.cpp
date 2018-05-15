//
//赤球(>2)と青球(>2)の個数を入力して球を２個取り出すとき少なくとも１つは赤球が出る確率
//

#include <stdio.h>

float calculate(float red, float blue){
	float parcentage;
	
	parcentage = 1 - ((blue * (blue - 1)) / ((blue + red) * (blue + red - 1)));
	
	return parcentage;
}

int main(void){
	float red, blue;
	float parcentage;

	printf("赤球の個数：");
	scanf("%f", &red);
	printf("青球の個数：");
	scanf("%f", &blue);
	if(red < 2 || blue < 2){
		printf("エラー\n");
	}
	else{
		parcentage = calculate(red, blue);

		printf("確率は%fです\n", parcentage);
	}
}
