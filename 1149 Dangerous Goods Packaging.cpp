#include<iostream>
#include<vector>
using namespace std;


//给出n组关联的数据，测试m组数据中有多少是关联的，有点绕
//测试当中如果有给出了特定的数据（在关联数据中有出现），就将关联数据传进测试vector中，再与原来的数据进行比较
//又是有点绕的说明 :)

vector<int> Hash[100000];
int main(){
    int n,m,i;
    cin>>n>>m;
    int a,b;
    for(i=0;i<n;i++){
        cin>>a>>b;
        Hash[a].push_back(b);
        Hash[b].push_back(a);
    }
    int k,j,num,flag,t;
    vector<int> s,test;
    for(i=0;i<m;i++){
        cin>>k;
        s.clear();
        test.clear();
        flag = 1;
        for(j=0;j<k;j++){
            cin>>num;
            test.push_back(num);
            if(Hash[num].size()!=0){
                for(t=0;t<Hash[num].size();t++){
                    s.push_back(Hash[num][t]);
                }
            }
        }
        for(t=0;t<k;t++){
            for(j=0;j<s.size();j++){
                if(s[j]==test[t]){
                    flag = 0;
                    break;
                }
            }
        }
        if(flag==0)
            cout<<"No"<<endl;
        else
            cout<<"Yes"<<endl;
    }
    system("pause");
    return 0;
}