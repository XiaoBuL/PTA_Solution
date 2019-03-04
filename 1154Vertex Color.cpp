#include<iostream>
#include<vector>
using namespace std;
#define Max 10001
int N,M;
int Graph[Max][Max]={0};
int color[Max];
int judge[Max];
int temp[Max];
void JudgeColor(int n);

int main(){
	int i,j;
	int a,b,K;
	cin>>N>>M;
	//邻接矩阵生成一个图 
	for(i=0;i<M;i++){
		cin>>a>>b;
		Graph[a][b] = Graph[b][a] = 1;
	}
	cin>>K;
	//测试颜色 
	for(i=0;i<K;i++){
		judge[i]= 0;
		for(j=0;j<N;j++)
			temp[j] = 0;		//temp数组是用来记录有多少个颜色的 ，初始化都为0； 
		for(j=0;j<N;j++){
			cin>>color[j];		//输入各个顶点的颜色 
			temp[color[j]] = 1;		 //颜色是用数字来表示的，所以哪个颜色有用到了，就为1； 
		}
		for(j=0;j<N;j++){
			if(temp[j]!=0)		//判断有几种颜色的 
				judge[i]++;	
		}
		JudgeColor(i);
		if(judge[i]!=0)
			cout<<judge[i]<<"-coloring"<<endl;
		else 
			cout<<"No"<<endl;
	}
}

void JudgeColor(int n){
	int flag=1;
	int i,j;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			if(Graph[i][j]==1){
				if(color[i]==color[j]){
					flag = 0;
					break;
				}
			}
		}
	}
	if(flag ==0)
		judge[n] = 0;
	return ;
}


	
