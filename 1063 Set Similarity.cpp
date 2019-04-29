#include<iostream>
#include<set>
using namespace std;

//一开始最后一个测试点没过,是因为申请的数组太小了

set<int> total[60];
int main(){
    int n;
    cin>>n;
    int i,j,num;
    for(i=1;i<=n;i++){
        int k;
        cin>>k;
        for(j=0;j<k;j++){
            cin>>num;
            total[i].insert(num);
        }
    }
    int test,a,b;
    cin>>test;
    for(i=0;i<test;i++){
        cin>>a>>b;
        set<int> new_set;
        new_set.clear();
        set<int>::iterator iter = total[a].begin();
        while(iter!=total[a].end()){
            new_set.insert(*iter);
            iter++;
        }
        iter = total[b].begin();
        while(iter!=total[b].end()){
            new_set.insert(*iter);
            iter++;
        }
        double pro = 1.0 * (total[a].size() + total[b].size() - new_set.size())/new_set.size();
        pro = pro * 100;
        printf("%.1f",pro);
        cout<<"%"<<endl;
    }
    system("pause");
    return 0;   
}