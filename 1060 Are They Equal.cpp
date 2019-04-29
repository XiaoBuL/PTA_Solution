#include<iostream>
#include<string>
using namespace std;
//第一次写的时候没有考虑到数字有小于0的情况

int main(){
    int n,i;
    string a,b,a_n,b_n;
    cin>>n;
    cin>>a>>b;
    //a的前面n位存储
    int k = 0,count_a,count_b;
    count_a = a.find(".");
    count_b = b.find(".");
    if(count_a ==a.npos)
        count_a = a.length();
    if(count_b == b.npos )
        count_b = b.length();
    i = 0;
    while(a[i]=='0'||a[i]=='.')    i++;
    if(count_a<=i)
        count_a = count_a - i+1;
    else   
        count_a = count_a -i;       //这题太阴了 正数前面也有可能是为0的
    if(i==a.length())
        count_a = 0;
    for(;i<a.length();i++){
        if(k==n)
            break;
        if(a[i]=='.')
           continue;
        a_n.push_back(a[i]);
        k++;
    }       //从非零的地方开始数起
    while(k<n){
        a_n.push_back('0');
        k++;
    }
    i = k = 0;
    while(b[i]=='0' ||b[i]=='.')    i++;
    if(count_b<=i)
        count_b = count_b - i +1;
    else
        count_b = count_b - i;
    if(b.length()==i)
        count_b = 0;
    for(;i<b.length();i++){
        if(k==n)
            break;
        if(b[i]=='.')
            continue;
        b_n.push_back(b[i]);
        k++;
    }
    while(k<n){
        b_n.push_back('0');
        k++;
    }
    if(a_n == b_n && count_a == count_b)
        printf("YES 0.%s*10^%d\n",a_n.c_str(),count_a);
    else
        printf("NO 0.%s*10^%d 0.%s*10^%d\n",a_n.c_str(),count_a,b_n.c_str(),count_b);
    system("pause");
    return 0;
}