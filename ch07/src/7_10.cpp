//任意の回数ローテーションさせるプログラム
//


#include <stdio.h>
#include <math.h> 

const int N = 7;//7個数字あるため

void swap(int& a,int b){

	a = b;

}

void output(int s[]){
	for(int i=0; i<N;i++){
		printf("%d",s[i]);
	}
	printf("\n");
}

void sort(int s[],int n){

	int s_[N];
	int num;

	for(int i=0; i<N;i++){
		s_[i] = s[i];
	}

	for(int i=0; i<N;i++){
		num = (n+i)%N;
		if(num<0){
			num = N+num;
		}
		swap(s[num],s_[i]);
	}

}



int main(void)
{
	int num_list[]={1,2,3,4,5,6,7};
	int n;

	printf("ローテーションさせる回数:");
	scanf("%d",&n);

	sort(num_list,n);
	output(num_list);
}


