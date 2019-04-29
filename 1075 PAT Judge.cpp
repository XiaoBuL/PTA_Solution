#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct node{
    int id;
    int problem[6];
    int total;
    int num;
    int rank;
};
int score[6];

bool cmp(node a,node b){
    if(a.total == b.total){
        if(a.num == b.num){
            return a.id < b.id;
        }
        return a.num>b.num;
    }
    return a.total>b.total;
}

int main(){
    int n,k,m;
    int i,uid,pid,s,j;
    cin>>n>>k>>m;
    vector<node> pat(n+1);
    pat[0].total = 0;
    for(i=1;i<=n;i++){
        pat[i].id = i;
        pat[i].total = 0;
        fill(pat[i].problem,pat[i].problem+k,-1);
        pat[i].num = 0;
    }
    for(i=1;i<=k;i++){
        cin>>score[i];
    }
    for(i=0;i<m;i++){
        cin>>uid>>pid>>s;
        if(s==score[pid])
            pat[uid].num++;
        if(s==-1)
            pat[uid].problem[pid] = 0;
        if(pat[uid].problem[pid]<s)
            pat[uid].problem[pid] = s;
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=k;j++){
            if(pat[i].problem[j]!=-1)
                pat[i].total += pat[i].problem[j];
        }
    }
    
    sort(pat.begin(),pat.end(),cmp);
    pat[0].rank = 1;
    int rank;
    for(i=0;i<=n;i++){
        if(pat[i].total == 0)
            break;
        if(i!=0){
            if(pat[i].total == pat[i-1].total)
                pat[i].rank = pat[i-1].rank;
            else
                pat[i].rank = i+1;
        }
        printf("%d %05d %d ",pat[i].rank,pat[i].id,pat[i].total);
        for(j=1;j<=k-1;j++){
            if(pat[i].problem[j] == -1)
                printf("- ");
            else
                printf("%d ",pat[i].problem[j]);
        }
        if(pat[i].problem[j] == 0)
            printf("-\n");
        else
            printf("%d\n",pat[i].problem[j]);
    }
    system("pause");
    return 0;
}