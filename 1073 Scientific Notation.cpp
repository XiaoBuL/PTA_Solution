#include<iostream>
#include<string>
#include<vector>
using namespace std;


//这题让我想了真是有一会

int str_int(string a){
    int sum = 0,i;
    for(i=1;i<a.size();i++){
        sum = sum * 10 + a[i] - '0';
    }
    return sum;
}

int main(){
    string in;
    cin>>in;
    vector<char> ch;
    //先判断是小于0还是大于0
    int pos = in.find("E");
    int len = in.size();    
    string a = in.substr(pos+1,len-pos);
    int notation = str_int(a);
    int i,j;
    for(i=0;i<pos;i++){
        if(in[i]!='.'&&in[i]!='+'&&in[i]!='-')
            ch.push_back(in[i]);
    }
    if(a[0] == '+'){
        if(in[0]=='-')
            cout<<"-";
        if(ch.size()-1 > notation){
            for(i=0;i<=notation;i++){
                cout<<ch[i];
            }
            cout<<".";
            for(;i<ch.size();i++)
                cout<<ch[i];
            system("pause");
            return 0;
        }
        for(i=0;i<ch.size();i++){
                cout<<ch[i];
        }
        for(j=0;j<notation-1;j++){
            cout<<"0";
        }
        cout<<endl;
    }
    else{
        if(in[i]=='-')
            cout<<"-";
        cout<<"0.";
        for(j=0;j<notation-1;j++)
            cout<<"0";
        for(i=0;i<ch.size();i++){
            if(ch[i]=='+')
                continue;
            else
                cout<<ch[i];
        }
    }
    system("pause");
    return 0;
}