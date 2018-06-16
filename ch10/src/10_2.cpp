//
//3つの値の数当てゲームを行う
//桁の場所と数があっていたら→ 1E
//桁の場所は異なるが数が含まれていたら→ 1B
//で表記する
//
#include <stdio.h>
#include <math.h> 

const int N=3;

int kazu(int *ans,int *num){

	int b=0;
	int e=0;

	for(int i=0;i<N;i++){

		for(int j=0;j<N;j++){

			if(*ans == *num){
				if(i == j)e++;
				else b++;
			}

			num++;
		}
		num = num - N; //numの先頭アドレスに戻した

		ans++;
	}

	printf("%dE,%dB",e,b);
	printf("\n");

	return e;
}

int input_array(int *num,int input){

	int div;
	div = pow(10,N-1);

	for(int i=0;i<N;i++){

		*num = input/div;
		input %=div;
		div /=10;

		num++;
	}
}

int error_confirm(int *num){
	int err = 0;

	if((num[0]==num[1])||(num[1]==num[2])||num[2]==num[0]) err = 1;
	
	if(num[0]=='\0'||num[1]=='\0'||num[2]=='\0') err = 1;

	return err;

}


int main(void)
{
	int ans_array[N] = {1,2,3};
	int *ans;
	ans = ans_array; //numのアドレスをnum_pに渡す

	int input;
	int num_[N];
	int error;//数が異なる3桁であるかの確認
	int break_value;

	while(1){

		printf("異なる3桁を入力してね\n");
		scanf("%d",&input);
		input_array(num_,input);

		error = error_confirm(num_);
		if(error == 1){
			printf("異なる3桁をにゅうりょくしろおおおおおお\n");
			continue;
		}


		int *ans_;
		ans_ = num_; //numのアドレスをnum_pに渡す
	
		break_value = kazu(ans,ans_);

		if(break_value == 3)break;

	}

	printf("congratulations!!!\n");

}

