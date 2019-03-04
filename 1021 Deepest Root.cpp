#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

//连接图的分量
vector<int> graph[10001];
int visit[10001] = {0};
int height[10001] = {0};
int MAX;

void dfs1(int index){
    visit[index] = 1;
    int i;
    for(i=0;i<graph[index].size();i++){
        if(!visit[graph[index][i]])
            dfs1(graph[index][i]);
    }
}

void dfs2(int index,int h){
    if(MAX<h)
        MAX = h;
    visit[index] = 1;
    int i;
    // cout<<index<<" ";
    for(i=0;i<graph[index].size();i++){
        if(!visit[graph[index][i]])
            dfs2(graph[index][i],h+1);
    }
}

int main(){
    int n,i;
    cin>>n;
    for(i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    int count = 0;
    for(i=1;i<=n;i++){
        if(!visit[i]){
            dfs1(i);
            count++;
        }
    }
    if(count>1){
        printf("Error: %d components\n",count);
        system("pause");
        return 0;
    }
    else{
        for(i=1;i<=n;i++){
            memset(visit,0,sizeof(visit));
            MAX = 0;
            dfs2(i,1);
            // cout<<endl;
            height[i] = MAX;
        }
        for(i=1;i<=n;i++){
            if(height[i]>MAX)
                MAX = height[i];
        }
       // cout<<MAX<<endl;
        for(i=1;i<=n;i++){
            if(height[i]==MAX)
                cout<<i<<endl;
        }
    }
    system("pause");
    return 0;
}