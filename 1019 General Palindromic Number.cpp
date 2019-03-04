#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<char> change;
    int n,b,i;
    cin>>n>>b;
    if(n == 0){
        cout<<"Yes"<<endl;
        cout<<"0"<<endl;
        return 0;
    }
    while(n){
        change.push_back(n%b);
        n /= b;
    }
    int flag = 1;
    for(i=0;i<change.size();i++){
        if(change[i]!=change[change.size()-i-1]){
            flag = 0;
            break;
        }
    }
    if(flag)
        cout<<"Yes"<<endl;
    else 
        cout<<"No"<<endl;
    for(i=change.size()-1;i>0;i--){
        printf("%d ",change[i]);
    }
    printf("%d\n",change[i]);
    system("pause");
    return 0;
}