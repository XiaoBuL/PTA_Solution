#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

//第一次就ac了 挺简单的

struct node{
    string id;
    int score;
    int final_rank;
    int location;
    int local_rank;
};

bool cmp(node a,node b){
    return a.score > b.score;
}

bool cmp2(node a,node b){
    if(a.score==b.score)
        return a.id < b.id;
    return a.score > b.score;
}

int main(){
    vector<node> local[101];
    vector<node> total;
    int n,k,i,j;
    cin>>n;
    string id;
    int score;
    struct node temp;
    for(i=1;i<=n;i++){
        cin>>k;
        for(j=0;j<k;j++){
            cin>>id;
            cin>>score;
            temp.id = id;
            temp.score = score;
            temp.location = i;
            local[i].push_back(temp);
        }
        sort(local[i].begin(),local[i].end(),cmp);
        for(j=0;j<local[i].size();j++){
            if(j==0)
                local[i][j].local_rank = j+1;
            else if(local[i][j-1].score == local[i][j].score)
                local[i][j].local_rank = local[i][j-1].local_rank;
            else
                local[i][j].local_rank = j+1;
            total.push_back(local[i][j]);
        }
    }
    sort(total.begin(),total.end(),cmp2);
    for(i=0;i<total.size();i++){
        if(i==0)
            total[i].final_rank = i+1;
        else if(total[i].score == total[i-1].score)
            total[i].final_rank = total[i-1].final_rank;
        else
            total[i].final_rank = i + 1;
    }
    cout<<total.size()<<endl;
    for(i=0;i<total.size();i++){
        cout<<total[i].id<<" "<<total[i].final_rank<<" "<<total[i].location<<" "<<total[i].local_rank<<endl;
    }
    system("pause");
    return 0;
}