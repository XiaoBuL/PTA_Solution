#include<stdio.h>
int main(){
	int a,b;
	int sum;
	if(scanf("%d%d",&a,&b)==1)
		return 0;
	sum = a+b;
	if(sum<0){
		sum = -sum;
		printf("-");
	}
	if(sum>=1000000){
		printf("%d,%03d,%03d",sum/1000000,(sum%1000000)/1000,sum%1000);
	}
	else if(sum>=1000){
		printf("%d,%03d",sum/1000,sum%1000);
	}
	else 
		printf("%d",sum);
	return 0;
}
