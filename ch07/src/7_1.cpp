
//
//配列の各要素を図6_1に示す7人のテストの点数で初期化して，平均，標準偏差を小数第2位まで表示する．
//また，それぞれの偏差値を小数第1位まで求める．
//
#include <stdio.h>

#include <math.h> 


const int N = 7;

float average(int* score){

	float ave;

	for(int i=0;i<N;i++){
		ave += score[i];
	}
	ave /= N;
	
	return ave;
}

float stdev(int* score,float ave){

	float stdev;

	for(int j=0;j<N;j++){
		stdev += (score[j] - ave) * (score[j] - ave);
	}
	stdev = sqrt(stdev) / N;

	return stdev;
}

void dev(int* score,float ave,float stdev){

	float dev;

	printf("偏差値\n");
	printf("西野  白石  秋元  橋本  齋藤  高山  生駒\n");
	for(int k=0;k<N;k++){
		dev = (score[k] - ave) * 10 / stdev + 50;
		printf("%.1f  ", dev);
	}
	printf("\n");

}


int main(void)
{
	int score[N] = {41, 30, 91, 85, 28, 66, 47};
	float ave;
	float stdev_ans;

	ave = average(score);
	printf("平均:%.2f\n", ave);

	stdev_ans = stdev(score,ave);
	printf("標準偏差：%.2f\n", stdev_ans);
	
	dev(score,ave,stdev_ans);
}

