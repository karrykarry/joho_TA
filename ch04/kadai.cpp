#include<stdio.h>
int main(void)
{
	int month = 0;
	printf("今日は何月ですか?");
	scanf("%d",&month);

	switch(month){
			case 1:  printf("1\n");
			case 2:  printf("2\n");
	}

}
