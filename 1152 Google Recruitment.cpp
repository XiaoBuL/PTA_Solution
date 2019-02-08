#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
int IsPrime(int n);

int main(){
	int L,K;
	int i,j,num;
	char P[1004];
	cin>>L>>K;
	cin>>P;
	for(i=0;i<L-K+1;i++){
		num = 0;
		for(j=0;j<K;j++){
			num += (P[i+j]-'0')*pow(10,K-j-1);
		}
		if(IsPrime(num)){
			for(j=0;j<K;j++){
				cout<<P[i+j];
			}
			cout<<endl;
			break;
		}
	}
	if(i==(L-K+1))
		cout<<"404"<<endl;
	return 0;
}

int IsPrime(int n){
	int i;
	if(n==2)
		return 1;
	for(i=2;i<=sqrt(n);i++){
		if(n%i == 0)
			return 0;
	}
	return 1;
}

