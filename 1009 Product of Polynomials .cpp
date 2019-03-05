#include<iostream>
#include<iomanip>

using namespace std;

int main(){
	int K1,K2,i,j;
	int Exp1[1001],Exp2[1001];
	int count=0,Exp;
	float Coe;
	float Coe1[1001] = {0.0};
	float Coe2[1001] = {0.0};
	float Product[2002] = {0.0};
	cin>>K1;
	for(i=0;i<K1;i++){
		cin>>Exp1[i];
		cin>>Coe1[Exp1[i]];
	}
	cin>>K2;
	for(i=0;i<K2;i++){
		cin>>Exp2[i];
		cin>>Coe2[Exp2[i]];
	}
	for(i=0;i<K1;i++){
		for(j=0;j<K2;j++){
			Exp = Exp1[i]+Exp2[j];
			Coe = Coe1[Exp1[i]] * Coe2 [Exp2[j]];
			Product[Exp] += Coe; 
		}
	}
	for(i=0;i<2002;i++){
		if(Product[i]!=0)
			count++;
	}
	cout<<count;
	for(i=2001;i>=0;i--){
		if(Product[i]!=0)
			cout<<" "<<i<<" "<<setiosflags(ios::fixed)<<setprecision(1)<<Product[i];
	}
	return 0;
}
