/*人口知能特論レポート課題(kNN法)
 *課題：テキスト（人口知能特論：第4回講義資料）p12に示した例題の内容を計算するプログラム
 *
 * プログラム言語：C言語
 * 文字コード：UTF-8
 * 1-NN,2-NN,3-NNの結果を表示
 *
 * 試験例と鋳型の値を変更しても算出できるように汎用性なプログラムにした
 * ただし，属性1，2，3 クラス の順かつクラスは1文字のアルファベットであること
 * 
 */
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
#define NDATA ((sizeof temp)/(sizeof (Data)))
using namespace std;


typedef struct {	//事例
	float num_1;	//属性1
	float num_2;	//属性2
	float num_3;	//属性3
	char group;		//クラス
	double ans;		//ユークリッド距離
} Data;


void euler_distance(Data s,Data* temp,int array_num){	//試験例と属性とのユークリッド距離の算出

	float dis;
	
	for(int i=0;i<array_num;i++){

		dis = sqrt(pow(s.num_1 - temp->num_1,2)+pow(s.num_2 - temp->num_2,2)+pow(s.num_3 - temp->num_3,2));
		temp->ans = dis;
		temp++;
	}
}


int compare(const void* a, const void* b)//ユークリッド距離の小さい順に並び替え
{
	const Data* p1 = (const Data*)a;
	const Data* p2 = (const Data*)b;

	int ndiff;

	ndiff = p1->ans - p2->ans;

	return ndiff;
}


void DispData(Data* out,int array_num)	//ディスプレイに出力して確認
{

	for(int i=0;i<array_num;i++){
		cout<<out[i].num_1<<","<<out[i].num_2<<","<<out[i].num_3<<","<<out[i].group<<","<<out[i].ans<<endl;
	}

}

void KNN(Data* temp,int num){// *-KNNに対応するような関数 * : 数字
	int count[100] = {0};
	int max = 0;//maxの数
	int max_i = 0;//maxの場所
	bool flag = false;

	for(int i=0;i<num;i++){
		if(('A'<=temp->group && temp->group<='Z') || ('a'<=temp->group && temp->group<='z')){
			count[temp->group - 'A']++;
		}
		temp++;
	}

	for(int i=0;i<num;i++){
		if(max<count[i]){
			flag = false;
			max = count[i];
			max_i = i;
		}

		else if(max == count[i]){
			flag = true;
		}
	}
	
	if(flag)printf("reject\n");	//{ki,..,kj}=max{k1,..,kk}のとき
	else printf("試験例のクラスは%c\n",'A'+max_i);

}


int main(void){

	Data temp[] = {				//すべての学習データ(鋳型)
		{2.2,0.3,20.9,'B',},
		{3.4,4.0,15.9,'A',},
		{1.4,2.8,34.3,'A',},
		{1.2,3.3,44.5,'B',}
	};


	Data s = {2.0,3.1,29.9,};	//試験例

	int array_num = sizeof temp / sizeof temp[0];

	euler_distance(s,temp,array_num);

	qsort(temp,NDATA,sizeof(Data),compare);
	
	// DispData(temp,array_num);	//ソートの結果を確認のための表示
	
	//各KNN
	cout<<"1-kk"<<endl;
	KNN(temp,1);
	cout<<"2-kk"<<endl;
	KNN(temp,2);
	cout<<"3-kk"<<endl;
	KNN(temp,3);

}

