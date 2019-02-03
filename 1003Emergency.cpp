#include<iostream>
#include<vector>
using namespace std;
#define INF 666666;

int main(){
	int Gragh[501][501] = {0};
	int Rescue[501] = {0};
	int visited[501] = {0};
	int weight[501];
	int dist[501];
	int num[501];
	int N,M,C1,C2,c1,c2,r,len,i,j; 
	int MinWeight;
	int visit;
	cin>>N>>M>>C1>>C2;
	for(i=0;i<N;i++){
		cin>>r;
		Rescue[i] = r; 
		dist[i] = INF;
	}
	for(i=0;i<M;i++){
		cin>>c1>>c2>>len;
		Gragh[c1][c2] = Gragh[c2][c1] = len;
	}
	
	dist[C1] = 0;
	num[C1] = 1;
	weight[C1] = Rescue[C1];
	
	for(i=0;i<N;i++){
		visit = -1;	
		MinWeight = INF;
		for(j=0;j<N;j++){
			if(visited[j] == 0&&dist[j]<MinWeight){
				visit = j;
				MinWeight = dist[j];
			}
		}
		if(visit==-1){
			break;
		}
		else{
			visited[visit] = 1;	
		}
		for(j=0;j<N;j++){
			if(visited[j]==0&&Gragh[visit][j]!=0){
				if(dist[visit]+Gragh[visit][j]<dist[j]){
					dist[j] = dist[visit] + Gragh[visit][j];
					num[j] = num[visit];
					weight[j] = weight[visit] + Rescue[j];
				}
			else if((dist[visit]+Gragh[visit][j]) == dist[j]){
				num[j] += num[visit];
				if(weight[visit]+Rescue[j]>weight[j]){
					weight[j] = weight[visit] + Rescue[j];
				}
			}
			}
		}
	}
	cout<<num[C2]<<" "<<weight[C2];
	return 0;
}


