#include<iostream>
#include<string>
using namespace std;


//一开始想复杂了，还想要用vector来解决输出的问题，想了一下发现没必要

int Hash[129];
int flag[129];

int main(){
    string original;
    string in;
    cin>>original;
    cin>>in;
    int i;
    for(i=0;i<in.size();i++){
        char ch = in[i];
        if(ch>='a'&&ch<='z')
            ch = ch - 'a' + 'A';
        Hash[ch] = 1;
    }
    for(i = 0;i<original.size();i++){
        char ch = original[i];
        if(ch>='a'&&ch<='z')
            ch = ch -'a'+'A';
        if(Hash[ch] == 0&&flag[ch] ==0 ){
            cout<<ch;
            flag[ch] =1;
        }
    }
    system("pause");
    return 0;    
}