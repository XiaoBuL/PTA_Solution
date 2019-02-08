#include<iostream>
#include<set>
#include<vector>
using namespace std;

struct node{
	int t1,t2;
};
int main(){
	int n,m,k;
	int i;
	cin>>n>>m;
	vector<node> v(m);
	for(i=0;i<m;i++){
		cin>>v[i].t1>>v[i].t2;
	}
	cin>>k;
	while(k--){
		int a[10002] = {0};
		int flag = 1;
		set<int> s;
		for(i=0;i<n;i++){
			cin>>a[i];
			s.insert(a[i]);
		}
		for(i=0;i<m;i++){
			if(a[v[i].t1]==a[v[i].t2]){
				flag = 0;
				break;
			}
		}
		if(flag)
			cout<<s.size()<<"-coloring"<<endl;
		else
			cout<<"No"<<endl;
	}
	return 0;
}
