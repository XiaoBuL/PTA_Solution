#include<iostream>
#include<vector>
using namespace std;
int N,heap[1001];
bool max_heap=true,min_heap=true;
vector<int> path;
void Path(int n);
int main(){
	int i;
	cin>>N;
	for(i=1;i<=N;i++){
		cin>>heap[i];
	}
	Path(1);
	if(max_heap)	
		cout<<"Max Heap";
	else if(min_heap==true)	
		cout<<"Min Heap";
	else 	cout<<"No Heap";
	return 0;
}

void Path(int n){
	int i;
	path.push_back(heap[n]);
	if(n*2>N){
		for(i = 0;i<path.size();i++){
			cout<<path[i];
			if(i>0){
				if(max_heap)
					max_heap = path[i-1]>=path[i];
				if(min_heap)
					min_heap = path[i-1]<=path[i];
			}
			if(i==path.size()-1)
				cout<<endl;
			else
				cout<<" ";
		}
	}
	else{
		if((n*2+1)<=N)	Path(n*2+1);
		if(n*2<=N)	Path(n*2);
	}
	path.pop_back();
}


