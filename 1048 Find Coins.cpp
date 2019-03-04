#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp(int a,int b){
    return a<b;
}
int main(){
    vector<int> num;
    int coin[1003]={0};
    int n,m;
    int i,c;
    cin>>n>>m;
    for(i=0;i<n;i++){
        cin>>c;
        coin[c]++;
        num.push_back(c);
    }
    int temp;
    sort(num.begin(),num.end(),cmp);
    //int flag = 0;
    for(i=0;i<num.size();i++){
        temp = num[i];
        if(coin[m-temp] !=0){
            if(m-temp==temp&&coin[temp]==1)
                continue;
            cout<<temp<<" "<<(m-temp)<<endl;
            system("pause");
            return 0;
        }
    }
    cout<<"No Solution\n";
    system("pause");
    return 0;
}