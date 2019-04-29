#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//DFS

//给的测试案例可以过 但是就是答案全错

vector<int> tree[10001];
vector<int> path;
vector<int> out[10001];
int Count = 0;
int weight[10001];
int w;

bool cmp(vector<int> a,vector<int> b){
    int i;
    int min_size = min(a.size(),b.size());
    for(i=0;i<min_size;i++){
        if(a[i]!=b[i])
            return a[i]>b[i];
    }
    if(a.size()>b.size())
        return a.size()>b.size();
    else
        return b.size()>a.size();
}

void DFS(int index,int sum){
    path.push_back(index);
    sum += weight[index];
    if(sum==24&&tree[index].size()==0){
        for(int i=0;i<path.size();i++){
            out[Count].push_back(weight[path[i]]);
        }
        Count++;
        path.pop_back();
        return;
    }
    else if(sum>24){
        path.pop_back();
        return;
    }
    for(int i=0;i<tree[index].size();i++){
        DFS(tree[index][i],sum);
    }
    path.pop_back();
}

int main(){
    int i,n,m;
    cin>>n>>m>>w;
    for(i=0;i<n;i++){
        cin>>weight[i];
    }
    int k,j,num1,num2;
    for(i=0;i<m;i++){
        cin>>num1>>k;
        for(j=0;j<k;j++){
            cin>>num2;
            tree[num1].push_back(num2);
        }
    }
    DFS(0,0);
    sort(out,out+Count,cmp);
    for(i=0;i<Count;i++){
        for(j=0;j<out[i].size()-1;j++)
            cout<<out[i][j]<<" ";
        cout<<out[i][j]<<endl;
    }
    system("pause");
    return 0;
}