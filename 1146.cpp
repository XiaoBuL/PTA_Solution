#include<stdio.h>
#include<stdlib.h>
#include<vector>
using namespace std;

int main(){
	int VertexNum,EdgeNum,V1,V2,num,i,V,j,k;
	int in[1001]={0},temp[1001];
	vector<int> Gragh[1001];
	vector<int> sort;
	scanf("%d%d",&VertexNum,&EdgeNum);
	for(i=0;i<EdgeNum;i++){
		scanf("%d%d",&V1,&V2);
		Gragh[V1].push_back(V2);
		in[V2]++;
	}		
	scanf("%d",&num);
	int flag ;
	for(i=0;i<num;i++){
		//保存入度数目 
		flag = 0;
		for(j=1;j<=VertexNum;j++){
			temp[j] = in[j];
		}
		//输入排序 
		for(j=0;j<VertexNum;j++){
			scanf("%d",&V);
			if(flag==1)
				continue;
			if(temp[V]!=0)	flag = 1;
			else{
				for(k=0;k<Gragh[V].size();k++){
					int Next = Gragh[V][k];
					temp[Next]--; 
				}
			}
		}
		if(flag==1)
			sort.push_back(i);
	}
	for(i=0;i<sort.size();i++){
		printf("%d",sort[i]);
		if(i!=sort.size()-1){
			printf(" ");
		}
	}
	return 0;
}
