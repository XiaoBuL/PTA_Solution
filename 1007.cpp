#include<iostream>
#include<vector> 
using namespace std;

int main(){
	int K,i,temp,sum,first,last,index;
	cin>>K;
	vector<int> num(K);
	sum = -1;
	first = 0;
	last = K-1;
	temp = 0;
	for(i=0;i<K;i++){
		cin>>num[i];
		temp+=num[i];
		if(temp<0){
			temp = 0;
			index = i+1;
		}
		else if(temp>sum){
			sum = temp;
			first = index;
			last = i;
		}
	}
	if(sum<0)
		sum = 0;
	cout<<sum<<" "<<num[first]<<" "<<num[last];
	return 0;
}

