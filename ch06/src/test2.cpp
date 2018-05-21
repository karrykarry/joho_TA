//
//アルファベットと数値を入力してその分小文字のアルファベットが進むように
//
//zを超えたらaに戻るように
//
#include<stdio.h>

#define ALPHA 26 //alphabetの数
// #define TEST //テストコード確認

char roop(int alpha, int num){//zを超えたらaに戻るように intで考えて文字を出力

	int ans;
	char ans_;

	ans = alpha + num;

	if(ans > 'z'){

		ans -= 'z';
		ans %= ALPHA;
		ans += 'a' - 1;

	}

	else if(ans < 'a'){//逆も然り
		
		ans = 'a' - ans;
		ans %= ALPHA;
		ans = 'z' - ans +1;

	}

	ans_ = ans;

	return ans_;
}


int main(void){

#ifdef TEST
	char alpha = 'z';
	int num = 1;

	printf("%cの%d進んだ先は%cで,aになることが確認\n",alpha,num,roop(alpha,num));


#else
	char x;
	int num;

	printf("どのアルファベットから始めるか:");
	scanf("%c",&x);

	printf("どのくらい進めるか:");
	scanf("%d",&num);

	printf("%cの%d進んだ先は%cです\n",x,num,roop(x,num));
#endif
}


