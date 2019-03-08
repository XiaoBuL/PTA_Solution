#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct node{
    int first;
    int second;
};

vector<node> match;
vector<int> men[10000],women[10000];    //存放关系图
bool cmp(node a,node b){
    return a.first!=b.first?a.first<b.first:a.second<b.second;
}

void Test(){
    int a,b,i,j,k;
    cin>>a>>b;
    match.clear();
    int flag = 0;
    struct node temp;
    int tempa,tempb;
    if(a<0 && b<0){
        a = -a; 
        for(i=0;i<women[a].size();i++){
            if(women[a][i]<0 && women[a][i]!=b){
                int index = -women[a][i];
                for(j=0;j<women[index].size();j++){
                    if(women[index][j]<0 && women[index][j]!=b){
                        int next = -women[index][j];
                        for(k=0;k<women[next].size();k++){
                            if(women[next][k] == b){
                                temp.first = index;
                                temp.second = next;
                                match.push_back(temp);
                            }
                        }
                    }
                }
            }
        }   
    }
    else if(a>0 && b<0){ 
        for(i=0;i<men[a].size();i++){
            if(men[a][i]>0){
                int index = men[a][i];
                for(j=0;j<men[index].size();j++){
                    if(men[index][j]<0 && men[index][j]!=b){
                        int next = -men[index][j];
                        for(k=0;k<women[next].size();k++){
                            if(women[next][k] == b){
                                temp.first = index;
                                temp.second = next;
                                match.push_back(temp);
                            }
                        }
                    }
                }
            }
        }
    }
    else if(a>0&&b>0){
        for(i=0;i<men[a].size();i++){
            if(men[a][i]>0 && men[a][i]!=b){
                int index = men[a][i];
                for(j=0;j<men[index].size();j++){
                    if(men[index][j]>0 && men[index][j]!=b){
                        int next = men[index][j];
                        for(k=0;k<women[next].size();k++){
                            if(women[next][k] == b){
                                temp.first = index;
                                temp.second = next;
                                match.push_back(temp);
                            }
                        }
                    }
                }
            }
        }  
    }
    else if(a<0&&b>0){
        a = -a;
        for(i=0;i<women[a].size();i++){
            if(women[a][i]<0){
                int index = -women[a][i];
                for(j=0;j<women[index].size();j++){
                    if(women[index][j]>0 && women[index][j]!=b){
                        int next = women[index][j];
                        for(k=0;k<men[next].size();k++){
                            if(men[next][k] == b){
                                temp.first = index;
                                temp.second = next;
                                match.push_back(temp);
                            }
                        }
                    }
                }
            }
        } 
    }
    sort(match.begin(),match.end(),cmp);
    cout<<match.size()<<endl;
    for(i=0;i<match.size();i++){
        cout<<match[i].first<<" "<<match[i].second<<endl;
    }
    return ;
}

//这个题目看下去贼复杂
int main(){
    int n,m,i;
    cin>>n>>m;
    int a,b;
    for(i=0;i<m;i++){
        cin>>a>>b;
        if(a<0)
            women[-a].push_back(b);
        else
            men[a].push_back(b);
        if(b<0)
            women[-b].push_back(a);
        else
            men[b].push_back(a);
    }
    int k;
    cin>>k;
    for(i=0;i<k;i++){
        Test();
    }
    system("pause");
    return 0;
}