//
//月と月始めの曜日を入力してカレンダーを表示する
//

#include <stdio.h>

int main(void){
	int month, day, day_of_week;
	int k = 0;

	printf("何月ですか？");
	scanf("%d", &month);
	printf("何曜日(日:0, 月:1, 火:2, 水:3, 木:4, 金:5, 土:6)始まりですか？");
	scanf("%d", &day_of_week);

	if(month<1 || 12<month || day_of_week<0 || 6<day_of_week){
		printf("エラー\n");
	}
	else{
		if(month==2){
			day = 28;
		}
		else if(month==4 || month==6 || month==9 || month==11){
			day = 30;
		}
		else{
			day = 31;
		}

		printf(" 日 月 火 水 木 金 土\n");
	
		for(int i=0;i<=6;i++){
			for(int j=1;j<=7;j++){
				if(i==0){
					if(k<day_of_week){
						printf("   ");
						k++;
					}
					else{
						printf("%3d", j-k);
					}
				}
				else if((7*i-day_of_week+j) > day){
					break;
				}
				else{
					printf("%3d", 7*i-day_of_week+j);
				}
			}
			printf("\n");
		}
	}
}


