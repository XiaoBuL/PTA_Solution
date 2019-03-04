#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int IsPrime(int n);
int GetPrime(int a);
//int Search(int num);
int main(){
	int MSize,N,M,i,Index,HashVal,num,j;
	double time,base;
	int *Hash,*Test;
	if(scanf("%d%d%d",&MSize,&N,&M)==0)
		return 0;
	if(!IsPrime(MSize))
		MSize = GetPrime(MSize);
	Hash = (int *)malloc(MSize*sizeof(int));
	Test = (int *)malloc(M*sizeof(int));
	for(i=0;i<N;i++)
		Hash[i] = 0;
	for(i=0;i<N;i++){
		if(scanf("%d",&num)==0)
			return 0;
		Index = 0;
		HashVal = num%MSize;
		for(j=0;j<=MSize;j++){
			if(Hash[(HashVal+j*j)%MSize]==0){
				Hash[(HashVal+j*j)%MSize] = num;
				break;
			}
		}
		if(j==MSize+1)
			printf("%d cannot be inserted.\n",num);
	}
	base = 0;	
	for(i=0;i<M;i++){
		if(scanf("%d",&num)==0)
			return 0;
		HashVal = num % MSize;
		for(j=0;j<=MSize;j++){
			if(Hash[(HashVal+j*j)%MSize]==num||Hash[(HashVal+j*j)%MSize]==0){
				base++;
				break;
			}
			base++;
		}
	}
	printf("%.1f",base/M);
	free(Hash);
	free(Test);
	return true;
}


//判断素数，并且找寻最小素数 
int IsPrime(int n){
	int i;
	for(i=2;i<=sqrt(n);i++){
		if(n%i==0)
			return 0;
	}
	return 1;
}
int GetPrime(int a){
	int i;
	while(!IsPrime(a)){
		a++;
	}
	return a;	
}
