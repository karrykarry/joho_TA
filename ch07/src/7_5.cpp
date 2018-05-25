//
//文字列"Rjnon%Zsn{jwxny‾"について，文字コードを5つずつ前にずらして表示する．
//また，整数型の配列{77,101,105,106,105,32,85,110,105,118,101,114,115,105,116,121,0}
//を文字型の配列で表示する．
//

#include <stdio.h>
#include <string.h>

int main(void)
{
	char str1[] = "Rjnon%Zsn{jwxny~";
	int str2[] = {77, 101, 105, 106, 105, 32,
		85, 110, 105, 118, 101, 114, 115, 105, 116, 121, 0};
	
	for(int i=0;i<strlen(str1);i++){
		str1[i] = str1[i] - 5;
	}
	printf("str1 : %s\n", str1);
	
	printf("str2 : ");
	for(int j=0;str2[j]!=0;j++){
		printf("%c", str2[j]);
	}

	printf("\n");

}
