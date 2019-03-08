#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
using namespace std;

// map 容器的 value 排序 ： 使用一个pair类型的vector进行排序
//20分 最后一个测试点没过去

struct node{
    int program;
    int mid;
    int Final;
    int sum;
};

bool cmp(const pair<string,node> a,const pair<string,node> b){
    if(a.second.sum==b.second.sum)
        return a.first < b.first;
    return a.second.sum > b.second.sum;
}

int main(){
    int p,m,f,i;
    cin>>p>>m>>f;
    map<string,node > students;
    string name;
    int score;
    for(i=0;i<p;i++){
        cin>>name;
        cin>>score;
        if(score<200)
            continue;
        else
            students[name].program = score;
    }
    for(i=0;i<m;i++){
        cin>>name;
        cin>>score;
        students[name].mid = score;
    }
    for(i=0;i<f;i++){
        cin>>name;
        cin>>score;
        students[name].Final = score;
    }
    map<string,node>::iterator iter;
    vector<pair<string,node> > out;
    for(iter=students.begin();iter!=students.end();iter++){
        if(iter->second.program<200)
            continue;
        if(iter->second.mid<60 && iter->second.Final<60)
            continue;
        if(iter->second.Final==0)
            continue;               //判断不应该输出的
        if(iter->second.mid==0)
            iter->second.mid = -1;
        if(iter->second.Final>iter->second.mid)
            iter->second.sum = iter->second.Final;
        else{
            int sum;
            sum = iter->second.mid * 0.4 + iter->second.Final * 0.6;
            if((iter->second.mid * 0.4 + iter->second.Final * 0.6 - sum) <0.5)
                iter->second.sum = sum;
            else
                iter->second.sum = sum+1;
        }
        if(iter->second.sum<60)
            continue;
        out.push_back(make_pair(iter->first,iter->second));
    }
    sort(out.begin(),out.end(),cmp);
    vector<pair<string,node> >::iterator it;
    for(it=out.begin();it!=out.end();it++)
        cout<<it->first<<" "<<it->second.program<<" "<<it->second.mid<<" "<<it->second.Final<<" "<<it->second.sum<<endl;
    system("pause");
    return 0;
}