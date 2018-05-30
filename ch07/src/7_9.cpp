//アスキーコード
//降順
//


#include <stdio.h>
#include <math.h> 

const int N = 1025;//最大

void input(char* s)
{
	printf("Type a string: ");
	scanf("%[^\n]",s);
}

void smalltobig(char& s){

	if('a'<=s && s<='z'){
		s -=0x20;
	}

}


void sort(char s[]){

	while(1){
		int swapcount = 0;
		for(int i=0; s[i];i++){
		if(s[i]==' ')smalltobig(s[i+1]);
		}
		if(!swapcount) break;
	}

}

int main(void)
{
	char str[N];

	input(str);
	sort(str);
	printf("%s\n",str);
}


