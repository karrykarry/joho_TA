//
//�z��̊e�v�f��}6_1�Ɏ���7�l�̃e�X�g�̓_���ŏ��������āC���ρC�W���΍���������2�ʂ܂ŕ\������D
//�܂��C���ꂼ��̕΍��l��������1�ʂ܂ŋ��߂�D
//

#include <stdio.h>
#include <math.h>

int main(void)
{
	const int N = 7;
	int score[N] = {41, 30, 91, 85, 28, 66, 47};
	float ave;
	float stdev;
	float dev;
	
	for(int i=0;i<N;i++){
		ave += score[i];
	}
	ave /= N;
	printf("���ρF%.2f\n", ave);
	
	for(int j=0;j<N;j++){
		stdev += (score[j] - ave) * (score[j] - ave);
	}
	stdev = sqrt(stdev) / N;
	printf("�W���΍��F%.2f\n", stdev);
	
	printf("�΍��l�F\n");
	printf("����  ����  �H��  ���{  �V��  ���R  ����\n");
	for(int k=0;k<N;k++){
		dev = (score[k] - ave) * 10 / stdev + 50;
		printf("%.1f  ", dev);
	}
}