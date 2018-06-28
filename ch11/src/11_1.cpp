#include<stdio.h>
#include<stdlib.h>

typedef double Matrix[4][4];


int main(void)
{
    
	
	FILE *fp;
	char *filename= "as_matrix_image.bin";
	double buf_[1000];
	
	if((fp= fopen(filename,"rb"))==NULL){
			printf("%sのエラー\n",filename);
			exit(1);
		}

	for(int i=0;i<16;i++)
	{
		fread(&buf_[i],sizeof(buf_[i]),16,fp);
		printf("%4.2f ",buf_[i]);
		if((i+1)%4 ==0 )printf("\n");

	}

	fclose(fp);

	return 0;


}
