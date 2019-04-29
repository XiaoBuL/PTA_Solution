#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//写得有点复杂了 一个半小时才写出来 我好菜啊 

struct node{
    int index;
    int rank;
};

bool cmp(node a,node b){
    return a.rank < b.rank;
}

int main(){
    int Np,Ng;
    cin>>Np>>Ng;
    int i,j;
    vector<int> seq(Np);
    vector<int> new_seq(Np);
    vector<int> weight(Np);
    vector<int> rank(Np);
    for(i=0;i<Np;i++){
        cin>>weight[i];
    }
    for(i=0;i<Np;i++){
        cin>>seq[i];
        new_seq[i] = seq[i];
    }
    int temp = Np,count = temp;      //Cout表示经过3轮结束比赛
    if(temp == 1){
        cout<<"1";
        return 0;
    }
    while(temp!=1){
        temp = (temp+Ng-1)/Ng;
        seq.clear();
        for(i=0;i<new_seq.size();i++){
            seq[i] = new_seq[i];
        }
        new_seq.clear();
        for(i=0;i<temp;i++){
            int max_index = 0;
            rank[seq[i*Ng + max_index]] = temp ;
            for(j=1;j<Ng;j++){
                if(i*Ng+j>=count)
                    break;
                if (weight[seq[i*Ng + max_index]] < weight[seq[i*Ng +j]]){
                    rank[seq[i*Ng+max_index]] = temp+1;
                    rank[seq[i*Ng+j]] = temp ;
                    max_index = j;
                }
                else
                    rank[seq[i*Ng+j]] = temp+1;
            }
            new_seq.push_back(seq[i*Ng+max_index]);       
        }
        count = temp;
    }
    vector<node> out(Np);
    for(i=0;i<Np;i++){
        out[i].index = i ;
        out[i].rank = rank[i];
    }
    sort(out.begin(),out.end(),cmp);
    for(i=0;i<Np-1;i++){
        if(i==0){
            rank[out[i].index] = i + 1;
            continue;
        }
        if(out[i].rank == out[i-1].rank){
            rank[out[i].index] = rank[out[i-1].index];
        }  
        else{
            rank[out[i].index] = i+1;
        }
    }
    if(i!=0)
        rank[out[i].index] = rank[out[i-1].index];
    for(i=0;i<Np-1;i++)
        cout<<rank[i]<<" ";
    cout<<rank[i];
    system("pause");
    return 0;
}