#include<iostream>
#include<string>
#include<vector>
using namespace std;

//首先一眼看下去 看不懂题意,看了几分钟之后懂了，还是比较有趣的一道题目
//可能判断条件有点多，没有整理

string describe(string a){
    int len = a.size();
    string next;
    char count;
    if(len==1){
        next += a[0];
        next += '1';
        return next;
    }
    for(int i = 0;i<len;i++){
        if(i==0){
            next+= a[i];
            count = '1';
            continue;
        }
        if(a[i] != a[i-1]){
            next += count;
            count = '1';
            next += a[i];
            if(i==len-1)
                next += count;
        }
        else{
            count++;
            if(i==len-1){
                next+=count;
            }   
        }
    }
    return next;
}

int main(){
    int i,n;
    char d;
    cin>>d>>n;
    string s;
    s += d;
    for(i=1;i<=n-1;i++){
        s = describe(s);
    }
    cout<<s<<endl;
    system("pause");
    return 0;
}