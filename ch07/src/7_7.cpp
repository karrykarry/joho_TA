//
//3つの英単語を読み込んで，すべての文字を大文字にして表示する．
//さらに大文字にした英単語を辞書順に並び替える．
//

#include <stdio.h>
#include <string.h>

void upper(char *str){

	for(int i=0;i<strlen(str);i++){
		if('a'<=str[i] && str[i]<='z'){
			str[i] = str[i] - 0x20;
		}
	}

}


int sort(char *str1, char *str2, char *str3){

	int number;

	while(number==0){
		if(strcmp(str1, str2)<0){
			if(strcmp(str1, str3)>0){
				number = 1;
			}
			else{
				if(strcmp(str2, str3)>0){
					number = 2;
				}
				else{
					number = 3;
				}
			}
		}
		else{
			if(strcmp(str2, str3)>0){
				number = 4;;
			}
			else{
				if(strcmp(str1, str3)>0){
					number = 5;
				}
				else{
					number = 6;
				}
			}
		}
	}


	return number;
}


int main(void)
{
	char str1[100];
	char str2[100];
	char str3[100];
	int number = 0;
	
	printf("英単語1を入力してください．");
	scanf("%s", str1);
	printf("英単語2を入力してください．");
	scanf("%s", str2);
	printf("英単語3を入力してください．");
	scanf("%s", str3);
	
	upper(str1);
	upper(str2);
	upper(str3);
	
	printf("大文字 : %s,%s,%s\n", str1, str2, str3);
	
	number = sort(str1,str2,str3);

	switch(number){
		case 6 : printf("辞書順 : %s,%s,%s\n", str2, str1, str3); break;
		case 5 : printf("辞書順 : %s,%s,%s\n", str2, str3, str1); break;
		case 4 : printf("辞書順 : %s,%s,%s\n", str3, str2, str1); break;
		case 3 : printf("辞書順 : %s,%s,%s\n", str1, str2, str3); break;
		case 2 : printf("辞書順 : %s %s %s\n", str1, str3, str2); break;
		case 1 : printf("辞書順 : %s %s %s\n", str3, str1, str2); break;
	}
}
