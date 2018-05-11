//
//座標を入力
//
//原点に対する距離のスカラー量を求めよ
//
//キーボードから入力せよ
//
#include<stdio.h>
#include<math.h>

//swap関数
float distance(int x,int y){

	float ans;

	ans = sqrt(x*x+y*y);

	return ans;

}



int main(void){

	int x;
	int y;
	float ans;

	printf("座標を入力\n");
	printf("x座標を入力せよ:");
	scanf("%d",&x);
	printf("y座標を入力せよ:");
	scanf("%d",&y);

	ans = distance(x,y);

	printf("距離：%f\n",ans);

}


