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

void swap(char& a,char& b){

	char c;

	c = a;
	a = b;
	b = c;

}

void sort(char s[]){

	while(1){
		int swapcount = 0;
		for(int i=0; s[i+1];i++){
			if(s[i]<s[i+1]){
				swap(s[i],s[i+1]);
				swapcount++;
			}
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

