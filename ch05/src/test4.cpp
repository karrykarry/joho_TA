//
//身長と体重を入力
//
//BMIと適正体重を算出
//
//キーボードから入力せよ
//
#include<stdio.h>
#include<math.h>

//BMI
//体重kg/(身長m)^2
float bmi(float h,float w){

	float ans;

	ans = w / (h * h);

	return ans;

}

//適正体重
//(身長m)^2*22
float proper(float h){

	return h*h*22;
}


int main(void){

	float h;//height
	float w;//weight
	float ans;

	printf("BMI及び適正体重を算出\n");
	printf("身長入力せよ[m]:");
	scanf("%f",&h);
	printf("体重を入力せよ[kg]");
	scanf("%f",&w);

	printf("BMI：%f,適正体重：%f\n",bmi(h,w),proper(h));

}



