#include<iostream>
#include<vector>
using namespace std;

//Ê÷µÄ²ãĞò±éÀú 
int main(){
	int N,M,i,j,k,parent,child,count;
	vector<int> Tree[101];
	int Node[501];
	int level[501];
	int queue[501];
	int front,rear;
	front = rear = 0;
	cin>>N>>M;
	if(N==0)
		return 0;	
	for(i=0;i<M;i++){
		cin>>parent>>k;
		for(j=0;j<k;j++){
			cin>>child;
			Tree[parent].push_back(child);
		}
	}
//	cout<<"debug1"<<endl;
	for(i=1;i<=N;i++){
		Node[i] = 0;
		level[i] = 0;
	} 
	//cout<<"debug"<<endl;
	Node[1] = 1;
	queue[rear++] = 1;
	while(front!=rear){
		parent = queue[front++];
		count = Node[parent];
		//cout<<level[parent]<<endl;
		if(Tree[parent].size()==0){
			level[count]++;
			continue;
		}
		for(i=0;i<Tree[parent].size();i++){
			child = Tree[parent][i];
			Node[child] = Node[parent] + 1;
			queue[rear++] = child;	
		}
	}
	for(i=1;i<count;i++){
		cout<<level[i]<<" ";
	}
	cout<<level[i];
	return 0;
}




