#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
using namespace std;
//运行超时错误

int main(){
    set<string> people;
    int n,k,i,course,num,j;
    cin>>n>>k;
    map<string,vector<int> > list;
    string name;
    for(i=0;i<k;i++){
        cin>>course>>num;
        for(j=0;j<num;j++){
            cin>>name;
            //people.insert(name);
            list[name].push_back(course);
        }
    }
    vector<int>::iterator it;
    for(i=0;i<n;i++){
        cin>>name;
        cout<<name<<" ";
        sort(list[name].begin(),list[name].end());
        cout<<list[name].size();
        for(j=0;j<list[name].size();j++){
            cout<<" "<<list[name][j];
        }
        cout<<endl;
    }
    // set<string>::iterator it;
    // for(it=people.begin();it!=people.end();it++){
    //     cout<<*it<<endl;
    // }
    system("pause");
    return 0;
}