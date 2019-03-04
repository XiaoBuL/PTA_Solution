#include<iostream>
using namespace std;
//找寻图的连通分量
int Gragh[1001][1001];
int visited[1001];
int n,m,k;

void DFS(int index){
    visited[index] = 1;
    for(int i=1;i<=n;i++){
        if(visited[i]==0 && Gragh[index][i]==1)
            DFS(i);
    }
}

int main(){
    int i,v1,v2;
    int test,num;
    cin>>n>>m>>k;
    for(i=0;i<m;i++){
        cin>>v1>>v2;
        Gragh[v1][v2] = Gragh[v2][v1] = 1;
    }
    for(i=0;i<k;i++){
        fill(visited,visited+1001,0);
        num = 0;
        cin>>test;
        visited[test] = 1;
        for(int j=1;j<=n;j++){
            if(visited[j]==0){
                DFS(j);
                num++;  
            }
        }
        cout<<num-1<<endl;
    }
    return 0;
}