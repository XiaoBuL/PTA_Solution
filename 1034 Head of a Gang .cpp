#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;
map<string,int> gang;
map<string,int> weight;
map<string,int> visit;
map<string,vector<string> > gragh;
int total = 0,cnt = 0;
string head;
map<string,int> res;
void dfs(string start){
    visit[start]=1;
    cnt++;
    total+=weight[start];
    if(weight[start]>weight[head])head=start;
    vector<string>::iterator it=gragh[start].begin();
 
    for(;it!=gragh[start].end();it++)
    {
       if(visit[*it]==0)
       {
           dfs(*it);
       }
    }
}
int main(){
    int n,k,i;
    int w,t,s=1;
    cin>>n>>k;
    string name1,name2;
    for(i=0;i<n;i++){
        cin>>name1>>name2>>t;
        weight[name1] += t;
        weight[name2] += t;
        gragh[name1].push_back(name2);
        gragh[name2].push_back(name1);
        visit[name1] = 0;
        visit[name2] = 0;
    }
    map<string,int>::iterator it = visit.begin();
    for(;it!=visit.end();it++){
        if(it->second==0){
            total = 0;
            cnt = 0;
            head = it->first;
            dfs(it->first);
        }
        if(cnt>2&&total/2>k)
            res[head] = cnt;
    }
    map<string,int>::iterator ite=res.begin();
    cout<<res.size()<<endl;
    for(;ite!=res.end();ite++)cout<<ite->first<<" "<<ite->second<<endl;
    system("pause");
    return 0;
}