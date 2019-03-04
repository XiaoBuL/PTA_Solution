#include<iostream>
#include<vector>
using namespace std;
int heap[1001];
int n,m;

void PostOrder(int index){
	if(index*2<=m)
		PostOrder(2*index);
	if(index*2+1<=m)
		PostOrder(2*index+1);		
	if(index==1)
		cout<<heap[index]<<endl;
	else
		cout<<heap[index]<<" ";
}

int main(){
	int i,j,temp;
	cin>>n>>m;
	for(i=0;i<n;i++){
		int Max = 1,Min = 1;
		for(j=1;j<=m;j++){
			cin>>temp;
			heap[j] = temp;
			if(j!=1){
				if(Max)
					Max = heap[j/2] >= heap[j];
				if(Min)
					Min = heap[j/2] <= heap[j];
			}
		}
		if(Max)
			cout<<"Max Heap"<<endl;
		else if(Min)
			cout<<"Min Heap"<<endl;
		else 
			cout<<"Not Heap"<<endl;
		PostOrder(1);
	}
	system("pause");
	return 0;
}




