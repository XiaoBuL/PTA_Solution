#include<iostream>
#include<vector>
#include<set>
using namespace std;

//题意没有理解circle是什么含义，总体还是很简单的，利用set来判断

int n,m;
int graph[201][201]={0};
int out=99999;
int outindex;
void judge(int index){
    int k,i,sum=0,flag=1;
    cin>>k;
    vector<int> test(k+1);
    test.clear();
    set<int> cycle;
    for(i=0;i<k;i++){
        cin>>test[i];
        cycle.insert(test[i]);
        if(i!=0){
            if(graph[test[i-1]][test[i]]==0)
                flag = 0;
            else
                sum += graph[test[i-1]][test[i]];
        }
    }
    if(flag==0){
        printf("Path %d: NA (Not a TS cycle)\n",index+1);
        return ;
    }
    if(cycle.size()<n||test[k-1]!=test[0]){
        printf("Path %d: %d (Not a TS cycle)\n",index+1,sum);
    }
    else if(test[k-1]==test[0]&&k==n+1){
        printf("Path %d: %d (TS simple cycle)\n",index+1,sum);
        if(sum<out){
            outindex = index+1;
            out = sum;
        }
    }
    else{
        printf("Path %d: %d (TS cycle)\n",index+1,sum);
        if(sum<out){
            outindex = index+1;
            out = sum;
        }
    }
    return ;
}

int main(){
    cin>>n>>m;
    int i,index;
    int a,b,c;
    for(i=0;i<m;i++){
        cin>>a>>b>>c;
        graph[a][b]  = graph[b][a] = c;
    }
    int k;
    cin>>k;
    for(i=0;i<k;i++){
        judge(i);
    }
    printf("Shortest Dist(%d) = %d\n",outindex,out);
    system("pause");
    return 0;
}