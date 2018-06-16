//
//ポインタを渡すと値がどうなるか
//またポインタが示すアドレスに格納された値を値渡し・参照渡しするとどうなるか
//
//問題例
// void pointer(int* n)
// {
// 	printf("計算前：%d\n",???);
// 	??? *= 2; //ポインタnに格納されている値を2倍にする
// 	printf("計算後：%d\n",???);
// }
//
// //値渡し
// void value(int n)
// {
// 	printf("計算前：%d\n",???);
// 	??? *= 2; //値nを2倍にする
// 	printf("計算後：%d\n",???);
// }
//
// //参照渡し
// void ref(int& n)
// {
// 	printf("計算前：%d\n",???);
// 	??? *= 2; //参照しているnに入っている値を2倍
// 	printf("計算後：%d\n",???);
// }
//
// int main(void)
// {
// 	int num = 1;
// 	int *num_p;
// 	num_p = ???; //numのアドレスをnum_pに渡す
//
// 	printf("ポインタ渡し前：%d\n",*num_p);
// 	pointer(???);
// 	printf("ポインタ渡し後：%d\n",*num_p);
// 	printf("\n");
//
// 	printf("値渡し前：%d\n",*num_p);
// 	value(???);
// 	printf("値渡し後：%d\n",*num_p);
// 	printf("\n");
//
// 	printf("参照渡し前：%d\n",*num_p);
// 	ref(???);
// 	printf("参照渡し後：%d\n",*num_p);
// 	printf("\n");
//
// }
//
//
//
//
//
#include <stdio.h>
#include <math.h> 


//ポインタを渡す
void pointer(int* n)
{
	printf("計算前：%d\n",*n);
	*n *= 2;
	printf("計算後：%d\n",*n);
}

//値渡し
void value(int n)
{
	printf("計算前：%d\n",n);
	n *= 2;
	printf("計算後：%d\n",n);
}

//参照渡し
void ref(int& n)
{
	printf("計算前：%d\n",n);
	n *= 2;
	printf("計算後：%d\n",n);
}

int main(void)
{
	int num = 1;
	int *num_p;
	num_p = &num; //numのアドレスをnum_pに渡す

	printf("ポインタ渡し前：%d\n",*num_p);
	pointer(num_p);
	printf("ポインタ渡し後：%d\n",*num_p);
	printf("\n");

	printf("値渡し前：%d\n",*num_p);
	value(*num_p);
	printf("値渡し後：%d\n",*num_p);
	printf("\n");

	printf("参照渡し前：%d\n",*num_p);
	ref(*num_p);
	printf("参照渡し後：%d\n",*num_p);
	printf("\n");

}


