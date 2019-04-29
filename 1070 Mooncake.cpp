#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


//一开始21分 一个段错误，一个答案错误
//改到23分了 没有段错误 一个答案错误 可能是特殊情况没考虑到
//看了ln大神的改了改自己的 觉得自己的输出判断实在太傻逼了

struct node{
    float ton;
    float price;
    float per;
};

bool cmp(node a,node b){
    return a.per > b.per;
}

int main(){
    int n,d;
    int i;
    cin>>n>>d;
    vector<node> mooncake(n);
    for(i=0;i<n;i++){
        cin>>mooncake[i].ton;
    }
    for(i=0;i<mooncake.size();i++){
        cin>>mooncake[i].price;
        mooncake[i].per = mooncake[i].price/mooncake[i].ton;
    }
    sort(mooncake.begin(),mooncake.end(),cmp);
    float sum = 0;
    for(i=0;i<n;i++){
        if(mooncake[i].ton <= d)
            sum += mooncake[i].price;
        else{
            sum += mooncake[i].per * d;
            break;
        }
        d -= mooncake[i].ton;
    }
    printf("%.2f",sum);
    system("pause");
    return 0;
}

