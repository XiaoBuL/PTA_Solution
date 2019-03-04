#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
using namespace std;
struct node{
    int time;
    int wait;
};
bool cmp(node a,node b){
    return a.time>b.time;
}
bool cmp2(int a,int b){
    return a>b;
}
int main(){
    int i,n,k,wait;
    int hour,minute,second,time;
    double total = 0; 
    int temp;
    //int window[101] = {-1};
    cin>>n>>k;
    vector<node> bank;
    vector<int> window;
    struct node a;
    int base = 28800;
    int limit = 61200;
    for(i=0;i<k;i++){
        window.push_back(base);
    }
    int count = 0;
    for(i=0;i<n;i++){
        scanf("%02d:%02d:%02d",&hour,&minute,&second);
        cin>>wait;
        time = hour*60*60 + minute*60 + second;
        a.time = time;
        a.wait = wait*60;
        if(time>61200)
            continue;
        count++;
        bank.push_back(a);
    }
    sort(bank.begin(),bank.end(),cmp);
    while(!bank.empty()){
        a = bank.back();
        bank.pop_back();
        sort(window.begin(),window.end(),cmp2);
        temp = window.back();
        window.pop_back();
        if(a.time<temp){
            total += temp - a.time;
            temp += a.wait;
        }
        else{
            temp = a.time + a.wait;
        }
        window.push_back(temp);
    }
    printf("%.1f",total/count/60.0);
    return 0;
}