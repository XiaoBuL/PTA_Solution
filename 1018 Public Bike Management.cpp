#include<iostream>
#include<vector>
#include<map>
using namespace std;
int Cmax,n,Sp,m;
int map[501][501] =  {0};
vector<int> store;

int main(){
    int i;
    int a,b,t;
    cin>>Cmax>>n>>Sp>>m;
    Cmax /= 2;
    for(i=0;i<n;i++){
        cin>>a;
        store.push_back(a);
    }
    for(i=0;i<m;i++){
        cin>>a>>b>>t;
        map[a][b] = map[b][a] = t;
    }
}