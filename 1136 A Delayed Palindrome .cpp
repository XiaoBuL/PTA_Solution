#include<iostream>
#include<string>
using namespace std;

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
    string s1,s2,s;
    cin>>s1;
    for(int i=0;i<10;i++){
        s2 = reserve(s1);
        s = Add(s1,s2);
        cout<<s1<<" + "<<s2<<" = "<<s<<endl;
        s1 = s;
        if(Judge(s)){
            cout<<s<<" is a palindromic number."<<endl;
            system("pause");
            return 0;
        }
    }
    cout<<"Not found in 10 iterations."<<endl;
    system("pause");
    return 0;
}