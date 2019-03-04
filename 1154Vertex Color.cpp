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
	//�ڽӾ�������һ��ͼ 
	for(i=0;i<M;i++){
		cin>>a>>b;
		Graph[a][b] = Graph[b][a] = 1;
	}
	cin>>K;
	//������ɫ 
	for(i=0;i<K;i++){
		judge[i]= 0;
		for(j=0;j<N;j++)
			temp[j] = 0;		//temp������������¼�ж��ٸ���ɫ�� ����ʼ����Ϊ0�� 
		for(j=0;j<N;j++){
			cin>>color[j];		//��������������ɫ 
			temp[color[j]] = 1;		 //��ɫ������������ʾ�ģ������ĸ���ɫ���õ��ˣ���Ϊ1�� 
		}
		for(j=0;j<N;j++){
			if(temp[j]!=0)		//�ж��м�����ɫ�� 
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


	
