//
// 天気によって 花火打ち上げ確認
// 
// for文
// 
// エラー処理込み
//

#include<stdio.h>

int main(void){

	int w_num;//天気
	int v_num;//風速
	int result;

	printf("天気を入力してください(晴れ:0,曇り:1,雨:2):");
	scanf("%d",&w_num);

	if(w_num == 0){

		printf("風速を入力してください(強い:0,弱い:1):");
		scanf("%d",&v_num);

		if(v_num == 0) printf("開催\n");
		else if(v_num == 1) printf("開催\n");
		else printf("エラー\n");

	}

	else if(w_num == 1){

		printf("風速を入力してください(強い:0,弱い:1):");
		scanf("%d",&v_num);

		if(v_num == 0) printf("延期\n");
		else if(v_num == 1) printf("開催\n");
		else printf("エラー\n");
	}

	else if(w_num == 2){

		printf("風速を入力してください(強い:0,弱い:1):");
		scanf("%d",&v_num);

		if(v_num == 0) printf("延期\n");
		else if(v_num == 1) printf("延期\n");
		else printf("エラー\n");
	}

	else {
		printf("エラー\n");
	}

	return(0);

}



