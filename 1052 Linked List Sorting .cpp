#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//坑：有的节点可能没在链表里面
struct node{
    int begin;
    int val;
    int end;
};

vector<node> List;
node rel[100000];

bool cmp(node a,node b){
    return a.val < b.val;
}

int main(){
    int n;
    int i,begin,a,b,c;
    cin>>n>>begin;
    for(i=0;i<n;i++){
        cin>>a>>b>>c;
        rel[a].begin = a;
        rel[a].val = b;
        rel[a].end = c;
    }
    for(i=begin;i!=-1;i=rel[i].end){
        List.push_back(rel[i]);
    }

    if(List.size()==0){
        cout<<"0 -1"<<endl;
        return 0;
    }

    sort(List.begin(),List.end(),cmp);
    cout<<List.size()<<" "<<List[0].begin<<endl;

    for(i=0;i<List.size()-1;i++){
        printf("%05d %d %05d\n",List[i].begin,List[i].val,List[i+1].begin);
    }
    printf("%05d %d -1\n",List[i].begin,List[i].val);
    
    system("pause");
    return 0;
}