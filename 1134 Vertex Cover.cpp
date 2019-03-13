#include<iostream>
#include<vector>
using namespace std;

vector<int> graph[100001];    //那么大的数组不能够在函数中进行申请，需要放入全局变量的堆栈空间中

int main(){
    int n,m,k,nv;
    int i,j;
    cin>>n>>m;
   
    for(i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(i);
        graph[b].push_back(i);
    }
    cin>>k;
    int num,t;
    for(i=0;i<k;i++){
        cin>>nv;
        vector<int> Hash(m,0);
        for(j=0;j<nv;j++){
            cin>>num;
            for(t = 0; t<graph[num].size();t++){
                int index = graph[num][t];
                Hash[index] = 1;
            }
        }
        int flag = 1;
        for(j=0;j<m;j++){
            if(Hash[j]==0){
                cout<<"No"<<endl;
                flag = 0;
                break;
            }
        }
        if(flag==1)
            cout<<"Yes"<<endl;
    }
    system("pause");
    return 0;
}
