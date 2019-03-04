#include<iostream>
#include<vector>
#include<stdlib.h>
#include<string>
#include<algorithm>
using namespace std;

bool cmp(string a,string b){
    return a+b<b+a;
}
int main(){
    int n,i,j;
    vector<string> seg;
    string s;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>s;
        seg.push_back(s);
    }
    sort(seg.begin(),seg.end(),cmp);
    string out;
    for(i=0;i<n;i++){
        out+=seg[i];
    }
    for(i=0;i<out.size()&&out[i]=='0';i++);
    if(i==out.size())
        cout<<"0";
    else
        cout<<(out.c_str()+i)<<endl;
    system("pause");
    return 0;
}