#include<iostream>
#include<vector>
#include<queue>
#include<math.h>
using namespace std;

//一开始 那个r没理解清楚，直接用BFS做就很快了

vector<int> tree[100001];
int number[100001];
int each[100001];

int main(){
    int n;
    double p,r,total;
    cin>>n>>p>>r;
    r = r/100;
    int k,a;
    queue<int> q;
    for(int i=0;i<n;i++){
        cin>>k;
        if(k==0){
            int num;
            cin>>num;
            number[i] = num;            
        }
        for(int j=0;j<k;j++){
            cin>>a;
            tree[i].push_back(a); 
        }
    }
    //队列的BFS
    each[0] = 0;
    q.push(0);
    while(!q.empty()){
        int index = q.front();
        q.pop();
        if(tree[index].size()==0){
            total = total + p * number[index] * pow(1+r,each[index]);
        }
        for(int i = 0;i<tree[index].size();i++){
            q.push(tree[index][i]);
            each[tree[index][i]] = each[index] + 1;
        }
    }

    printf("%.1f",total);
    system("pause");
    return 0;
}