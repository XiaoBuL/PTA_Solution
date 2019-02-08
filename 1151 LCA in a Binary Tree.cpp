#include<iostream>
#include<vector>
#include<map>
using namespace std;
void LCA(int in_left,int in_right,int pre_root,int a,int b);
int *in,*pre;
map<int,int> tree;

int main(){
	int N,M;
	int i,a,b;
	cin>>M>>N;
	in = new int[N+1];
	pre = new int[N+1];
	for(i=1;i<=N;i++){
		cin>>in[i];
		tree[in[i]] = i;
	}
	for(i=1;i<=N;i++){
		cin>>pre[i];
	}
	for(i=0;i<M;i++){
		cin>>a>>b;
		if(tree[a]==0&&tree[b]==0)
			cout<<"ERROR: "<<a<<" and "<<b<<" are not found."<<endl;
		else if(tree[a]==0)
			cout<<"ERROR: "<<a<<" is not found."<<endl;
		else if(tree[b]==0)
			cout<<"ERROR: "<<b<<" is not found."<<endl;
		else 
			LCA(1,N,1,a,b);
	}
	delete(in);
	delete(pre);
	return 0;
}

void LCA(int in_left,int in_right,int pre_root,int a,int b){
	if(in_left>in_right)
		return;
	int in_root,a_in_index,b_in_index;
	in_root = tree[pre[pre_root]];//得到中序的根 
	a_in_index = tree[a];
	b_in_index = tree[b];
	if(a_in_index < in_root && b_in_index < in_root)
		LCA(in_left,in_root-1,pre_root+1,a,b);
	else if((a_in_index<in_root&&b_in_index>in_root)||(a_in_index>in_root&&b_in_index<in_root))
		cout<<"LCA of "<<a<<" and "<<b<<" is "<<in[in_root]<<"."<<endl;
	else if(a_in_index>in_root&&b_in_index>in_root)
		LCA(in_root+1,in_right,pre_root+1+(in_root-in_left),a,b);
	else{
		if(a_in_index == in_root)
			cout<<a<<" is an ancestor of "<<b<<"."<<endl;
		else if(b_in_index == in_root)
			cout<<b<<" is an ancestor of "<<a<<"."<<endl;
	}
}


