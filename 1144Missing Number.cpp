#include<stdio.h>

int main(){
	int N,i,m,Max;
	int data[100001] ={0};
	if(scanf("%d",&N)==0)
		return 0;
	Max = 0;
	for(i=0;i<N;i++){
		if(scanf("%d",&m)==0)
			return 0;
		if(m>Max)
			Max = m;
		if(m>0&&m<100001)
			data[m] = 1;
	}
	if(Max==0){
		printf("1");
		return 0;
	}
	for(i=1;i<=Max;i++){
		if(data[i] == 0){
			printf("%d",i);
			return 0;
		}
	}
	printf("%d",Max+1);
	return 0;
}

