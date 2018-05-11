//
// 長方形を作ろう
//

#include<stdio.h>

int main(void){

	int height;
	int width;

	printf("たての長さ:");
	scanf("%d",&height);

	printf("よこの長さ:");
	scanf("%d",&width);

	for(int i=0;i<height;i++){

	for(int j=0;j<width;j++){

		printf("# ");
	}
	printf("\n");
	}


	return(0);

}


