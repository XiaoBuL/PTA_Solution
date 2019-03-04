#include<iostream>
#include<vector>
using namespace std;
int Gragh[201][201] = {0};
int JudgeClique(vector<int> V);
int JudgeMax(vector<int> V);
int Nv,Ne;

int main(){
	int i,v1,v2,K,num,j,m;
	int IsClique,IsMax;
	char* ch;
	cin>>Nv>>Ne;
	for(i=0;i<Ne;i++){
		cin>>v1>>v2;
		Gragh[v1][v2] = Gragh[v2][v1] = 1;
	}
	cin>>K;
	vector<int> Test[K];
	vector<int> Result;
	for(i=0;i<K;i++){
		cin>>m;
		Test[i].resize(m);
		for(j=0;j<m;j++){
			cin>>num;
			Test[i][j] = num;		
		}
	}
	for(i=0;i<K;i++){
		IsClique = JudgeClique(Test[i]);
		IsMax = JudgeMax(Test[i]);	
		if(IsClique == 0)
			cout<<"Not a Clique"<<endl;
		else if(IsMax == 0)
			cout<<"Not Maximal"<<endl;
		else 
			cout<<"Yes"<<endl;	
	}
	return 0;
}

int JudgeClique(vector<int> V){
	int i,j;
	for(i=0;i<V.size();i++){
		for(j=i+1;j<V.size();j++){
			if(Gragh[V[i]][V[j]]==0)
				return 0;
		}
	}
	return 1;
}

int JudgeMax(vector<int> V){
	int i,flag,j;
	if(V.size()==1)
		return 1;
	for(i=1;i<=Nv;i++){
		flag = 1;
		for(j=0;j<V.size();j++)
			if(i==V[j])
				flag = 0;
		if(flag==0)
			continue;
		for(j=0;j<V.size();j++){
			if(Gragh[V[j]][i]==1)
				flag = 1;
			else {
				flag = 0;
				break;
			}
		}
		if(flag == 1)
			return 0;
	}		
	return 1;
}

