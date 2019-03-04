#include<iostream>
#include<vector>
using namespace std;
int tree[1001];
vector<int> p;
int Max = 1,Min = 1;
int n;
void dfs(int index){
    int i;
    p.push_back(tree[index]);
    if(index*2>n){
        for(i=0;i<p.size();i++){
            cout<<p[i];
            if(i>0){
                if(Max)
                    Max = p[i-1]>=p[i];
                if(Min)
                    Min = p[i-1]<=p[i];
            }
            if(i+1!=p.size())   cout<<" ";
            else
            {
                cout<<endl;
            }
        }
    }
    else{
        if(i*2+1<=n)    dfs(i*2+1);
        if(i*2<=n)  dfs(i*2);
    }
    p.pop_back();
}

int main(){
    cin>>n;
    int i;
    for(i=1;i<=n;i++){
        cin>>tree[i];
    }
    for(i=0;i<n;i++){
        cout<<tree[i]<<" ";
    }
    dfs(1);
    if(Max) cout<<"Max Heap"<<endl;
    else if(Min) cout<<"Min Heap"<<endl;
    else    cout<<"No Heap"<<endl;
    system("pause");
    return 0;
}