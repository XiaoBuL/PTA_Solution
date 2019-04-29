#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
//图的节点不是数字，而是有字母
//如何生成一个包含字母节点名字的图,不会写

const int inf = 99999999;
int dist[1020];
int visit[1020];
int graph[1020][1020];

int main(){
    int n,m,num,ds;
    cin>>n>>m>>num>>ds;
    int i;
    string a,b;
    int distance;
    fill(graph[0],graph[0]+1020*1020,inf);
    for(i=0;i<num;i++){
        cin>>a>>b>>distance;
        int e1,e2;
        if(a[0]=='G'){
            a = a.substr(1);
            e1 = n + stoi(a);
        }
        else
            e1 = stoi(a);
        if(b[0] == 'G'){
            b = b.substr(1);
            e2 = n + stoi(b);
        }
        else
            e2 = stoi(b);
        graph[e1][e2] = graph[e2][e1] = distance;
    }
    int j,k;
    int Outid = -1;
    double Outmin = -1,Outavage = 0;
    for(int index=n+1;index<=n+m;index++){
        fill(dist,dist+1020,inf);
        fill(visit,visit+1020,0);
        dist[index] = 0;
        visit[index] = 1;
        //Dijkstra算法
        double min = inf ,avage = 0;
        for(i=0;i<n+m;i++){
            int small_vertex = -1,minds = inf;
            for(j=1;j<=n+m;j++){
                if(visit[j]==0 && dist[j] < minds){
                    minds = dist[j];
                    small_vertex = j;
                }
            }
            if(small_vertex==-1)    break;
            visit[small_vertex] = 1;
            for(k=1;k<=n+m;k++){
                if(visit[k] == 0 && dist[k] > dist[small_vertex] + graph[k][small_vertex])
                    dist[k] = dist[small_vertex] + graph[k][small_vertex];
            }
        }
        for(i=1;i<=n;i++){
            if(dist[i] > ds){
                min = -1;
                break;
            }
            if(dist[i] < min) min = dist[i];
            avage += 1.0 * dist[i];
        }
        if(min == -1) continue;
        avage = avage / n;
        if(min<Outmin){
            Outavage = avage;
            Outmin = min;
            Outid = index;
        }
        else if( min == Outmin && avage < Outavage){
            Outid = index;
            Outavage = avage;
        }
    }
    if(Outid == -1 )
        cout<<"No Solution\n";
    else
        printf("G%d\n%.1f %.1f\n",Outid-n,Outmin,Outavage);
    system("pause");
    return 0;
}



