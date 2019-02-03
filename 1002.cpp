#include<stdio.h>
int main(){
	int Ka,Kb,i,count=0;
	int N;
	double a[1001],Coe;
	for(i=0;i<1001;i++)
		a[i] = 0;
	if(scanf("%d",&Ka)==0)
		return 0;	
	for(i=0;i<Ka;i++){
		if(scanf("%d",&N)==0)
			return 0;	
		if(scanf("%lf",&Coe)==0)
			return 0;
		a[N] += Coe;
	}
	if(scanf("%d",&Kb)==0)
		return 0;
	for(i=0;i<Kb;i++){
		if(scanf("%d",&N)==0)
			return 0;	
		if(scanf("%lf",&Coe)==0)
			return 0;
		a[N] += Coe;
	}
	for(i=1000;i>=0;i--){
		if(a[i]!=0)
			count++;
	}
	printf("%d",count);
	for(i=1000;i>=0;i--){
		if(a[i]!=0){
			printf(" %d %.1f",i,a[i]);
		}
	}
	printf("\n");
	return 0;
}
