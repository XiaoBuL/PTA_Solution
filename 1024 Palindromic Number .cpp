#include<iostream>
#include<string>
using namespace std;
//字符串的反过来相加 
//两个测试点不知道为什么过不去

int Judge(string s){
    int len = s.size();
    int i;
    for(i = 0;i<len;i++){
        if(s[i]!=s[len-i-1])
            return 0;
    }
    return 1;
}

string Add(string a,string b){
    int numa,numb,carry = 0,temp;
    string out = a;
    int len = a.size(),i;
    for(i = len-1 ; i>=0 ; i--){
        numa = a[i] - '0';
        numb = b[i] - '0';
        temp = (numa + numb + carry) % 10;
        carry = (numa + numb + carry) / 10;
        out[i] = temp + '0';
    }
    if(carry == 1){
        out = '1' + out;
    }
    return out;
}

string reserve(string a){
    string b = a;
    int i,len = a.size();
    for(i=0;i<len;i++){
        b[i] = a[len-i-1];
    }
    return b;
}


int main(){
    string n,s;
    cin>>n;
    int k,i;
    cin>>k;
    for(i=1;i<=k;i++){
        s = reserve(n);
        s = Add(s,n);
        n = s;
        if(Judge(s)){
            cout<<s<<endl;
            cout<<i<<endl;
            system("pause");
            return 0;
        }
    }
    cout<<s<<endl;
    cout<<k<<endl;
    system("pause");
    return 0;
}