#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

//第一遍没有考虑 0 的情况 12分
//三个测试点没过
string num[10] = { "ling","yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu" };
string c[6] = { "Ge","Shi", "Bai", "Qian", "Yi", "Wan" };

int main(){
    int n;
    cin>>n;
    if(n==0){
        cout<<"ling";
        return 0;
    }    
    if(n<0){
        cout<<"Fu ";
        n = -n;
    }
    int part[3];
    part[0]= n / 100000000; 
    part[1]= (n % 100000000) / 10000;
    part[2] = n % 10000;
    int flag = 0 ;
    if(part[0]!=0){
        cout<<part[0]<<" Yi";
    }
    if(part[1]==0&&){
        cout<<" Wan";
    }
    else{

    }
    if(part[2]!=0){
        
    }

    system("pause");
    return 0;
}