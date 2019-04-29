#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

//运行超时有点麻烦,莫名其妙就超时了 也不知道为什么

struct node{
    string id;
    string name;
    int score;
};

int c=1;

bool cmp(node a,node b){
    if(c==1){
        return a.id < b.id;
    }
    if(c==2){
        if(a.name == b.name)
            return a.id < b.id;
        return a.name < b.name;
    }
    if(c==3){
        if(a.score == b.score)
            return a.id < b.id;
        return a.score < b.score;
    }
}

int main(){
    vector<node> excel;
    int k,n;
    cin>>n>>k;
    int i;
    c = k;
    string id;
    string name;
    int score;
    struct node temp;
    for(i=0;i<n;i++){
        cin>>id>>name;
        cin>>score;
        temp.id = id;
        temp.name = name;
        temp.score = score;
        excel.push_back(temp);
    }    

    sort(excel.begin(),excel.end(),cmp);    //超时问题

    for(i=0;i<excel.size();i++){
        cout<<excel[i].id<<" "<<excel[i].name<<" "<<excel[i].score<<endl;
    }
    system("pause");
    return 0;
}