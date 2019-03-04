#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<string>
using namespace std;

int main(){
    vector<string> course[2501];
    int n,k;
    int i,j,c,num;
    cin>>n>>k;
    for(i=0;i<n;i++){
        string name;
        cin>>name;
        cin>>c;
        for(j=0;j<c;j++){
            cin>>num;
            course[num].push_back(name);
        }
    }
    for(i=1;i<=k;i++){
        sort(course[i].begin(),course[i].end());
    }
    for(i=1;i<=k;i++){
        cout<<i<<" "<<course[i].size()<<endl;
        for(j=0;j<course[i].size();j++){
            cout<<course[i][j]<<endl;
        }
    }
    system("pause");
    return 0;
}