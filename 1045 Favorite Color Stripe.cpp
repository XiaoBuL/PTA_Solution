#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n,m,l;
    int i,color,j;
    int favorite[201];
    vector<int> stripe;
    cin>>n;
    cin>>m;
    for(i=1;i<=m;i++){
        cin>>color;
        favorite[color] = i;
    }
    cin>>l;
    for(i=0;i<l;i++){
        cin>>color;
        if(favorite[color]>=1){
            stripe.push_back(favorite[color]);
        }
    }
    int Max = 0;
    int dp[10001];
    for(i=0;i<stripe.size();i++){
        dp[i] = 1;
        for(j=0;j<i;j++){
            if(stripe[i]>=stripe[j]){
                dp[i] = max(dp[i],dp[j]+1);
            }
        }
        Max = max(dp[i],Max);
    }
    cout<<Max;
    system("pause");
    return 0;
}