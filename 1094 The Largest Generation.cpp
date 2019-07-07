#include<iostream>
#include<vector>
using namespace std;


vector<int> Hash[101];
vector<int> Floor[101];

int main(){
    int n,m;
    cin>>n>>m;
    int i,j;
    int father,son,num;
    for(i=0;i<m;i++){
        cin>>father;
        cin>>num;
        for(j=0;j<num;j++){
            cin>>son;
            Hash[father].push_back(son);
        }
    }
    Floor[1].push_back(1);
    int k = 1;
    while(!Floor[k].empty()){
        for(i=0;i<Floor[k].size();i++){
            int index = Floor[k][i];
            for(j=0;j<Hash[index].size();j++){
                Floor[k+1].push_back(Hash[index][j]);
            }
        }
        k++;
    }
    int max = 0;
    int level = 0;
    for(i=1;i<k;i++){
        if(max < Floor[i].size())
        {
            max = Floor[i].size();
            level = i ;
        }
        
    }
    cout<<max<<" "<<level<<endl;
    system("pause");
    return 0;
}
