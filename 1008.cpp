#include<iostream>
using namespace std;

int main(){
	int N,i,floor,total=0;
	int stay=0;
	cin>>N;
	for(i=0;i<N;i++){
		cin>>floor;
		if(floor==stay){
			total+=5;
			continue;
		}
		if(floor>stay)
			total+= (floor-stay)*6+5;
		else 
			total+= (stay-floor)*4+5;
		stay = floor;
	}
	cout<<total;
	return 0;
}
