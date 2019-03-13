#include<iostream>
#include<vector>

using namespace std;

//有些不是字母的编号可以用int类型来代替，没必要用string
//教训：Hash 可以用int类型数组实现，并且最后输出要设置格式

struct node{
    int begin;
    int val;
    int end;
};
node Hash[100001];
vector<node> List;
vector<node> out;
int main(){
    int begin,n,k,i,j;
    cin>>begin>>n>>k;
    int a,b,c;
    for(i=0;i<n;i++){
        cin>>a>>b>>c;
        Hash[a].begin = a;
        Hash[a].val = b;
        Hash[a].end = c;        
    }
    while(begin!=-1){
        List.push_back(Hash[begin]);
        begin = Hash[begin].end;
    }
    for(i=0;i<List.size();i++){
        if(List[i].val<0)
            out.push_back(List[i]);
    }
    for(i=0;i<List.size();i++){
        if(List[i].val>=0&&List[i].val<=k)
            out.push_back(List[i]);
    }
    for(i=0;i<List.size();i++){
        if(List[i].val>k)
            out.push_back(List[i]);
    }
    for(i=0;i<out.size()-1;i++){
        printf("%05d %d %05d\n",out[i].begin,out[i].val,out[i+1].begin);
    }
    printf("%05d %d -1\n",out[i].begin,out[i].val);
    system("pause");
    return 0;
}