#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct node{
    int id;
    int virtue;
    int talent;
};
bool cmp(node a,node b){
    //圣人排名
    if(a.virtue+a.talent == b.virtue + b.talent){
        if(a.virtue==b.virtue)
            return a.id < b.id;
        else
            return a.virtue>b.virtue;
    }
    else 
        return (a.talent+a.virtue) > (b.talent + b.virtue);
}

int main(){
    int n,l,h;
    cin>>n>>l>>h;
    int id,v,t;
    vector<node> out;
    vector<node> sage;
    vector<node> noblemen;
    vector<node> fool;
    vector<node> small;
    node temp;
    while(n--){
        cin>>id>>v>>t;
        if(v<l||t<l){
            continue;
        }
        temp.id = id;
        temp.virtue = v;
        temp.talent = t;
        out.push_back(temp);
    }
    for(int i = 0;i<out.size();i++){
        if(out[i].talent>=h&&out[i].virtue>=h)
            sage.push_back(out[i]);
        else if(out[i].virtue>=h&&out[i].talent<h)
            noblemen.push_back(out[i]);
        else if(out[i].virtue<h&&out[i].talent<h&&out[i].virtue>=out[i].talent)
            fool.push_back(out[i]);
        else 
            small.push_back(out[i]);
    }
    if(sage.size()!=0)
        sort(sage.begin(),sage.end(),cmp);
    if(noblemen.size()!=0)
        sort(noblemen.begin(),noblemen.end(),cmp);
    if(fool.size()!=0)
        sort(fool.begin(),fool.end(),cmp);
    if(small.size()!=0)
        sort(small.begin(),small.end(),cmp);
    cout<<out.size()<<endl;
    for(int i =0;i<sage.size();i++)
        cout<<sage[i].id<<" "<<sage[i].virtue<<" "<<sage[i].talent<<endl;
    for(int i =0;i<noblemen.size();i++)
        cout<<noblemen[i].id<<" "<<noblemen[i].virtue<<" "<<noblemen[i].talent<<endl;
    for(int i =0;i<fool.size();i++)
        cout<<fool[i].id<<" "<<fool[i].virtue<<" "<<fool[i].talent<<endl;
    for(int i =0;i<small.size();i++)
        cout<<small[i].id<<" "<<small[i].virtue<<" "<<small[i].talent<<endl;
    
    system("pause");
    return 0;
}