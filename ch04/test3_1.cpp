//
// 天気によって 花火打ち上げ確認
// 
// switch
//
// エラー処理込み
// 

#include<stdio.h>

int main(void){

	int w_num;//天気
	int v_num;//風速
	int result;



	while(1){
		printf("天気を入力してください(晴れ:0,曇り:1,雨:2):");
		scanf("%d",&w_num);
		if(w_num != 0 && w_num != 1 && w_num != 2 ){
			printf("エラー\n");
			break;
		}

		printf("風速を入力してください(強い:3,弱い:0):");
		scanf("%d",&v_num);
		if(v_num != 0 && v_num != 3 ){
			printf("エラー\n");
			break;
		}

		result = w_num + v_num;

		switch(result){

			case 0: printf("開催\n"); break;
			case 1: printf("開催\n"); break;
			case 2: printf("延期\n"); break;

			case 3: printf("開催\n"); break;
			case 4: printf("延期\n"); break;
			case 5: printf("延期\n"); break;

		}
		break;
	}
	return(0);

}


