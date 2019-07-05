#include<iostream>
#include<vector>
using namespace std;
//这题有个 bug 是 空的vector的size - 1 竟然是一个很大的数 有点不懂


struct node{
    int begin;
    int value;
    int end;
};
node Hash[100031];
int num[100031] = {0};
vector<node> List1;
vector<node> List2;

int main(){
    int root,n,i;
    cin>>root>>n;
    int begin,value,end;
    node temp;
    for(i=0;i<n;i++){
        cin>>begin>>value>>end;
        temp.begin = begin;
        temp.value = value;
        temp.end = end;
        Hash[begin] = temp;
    }
    begin = root;
    for(i=0;i<n;i++){
        int index = Hash[begin].value;
        index = index>0?index:-index;
        if(num[index] == 1)
            List2.push_back(Hash[begin]);
        else{
            num[index] = 1;
            List1.push_back(Hash[begin]);
        }
        begin = Hash[begin].end;
        if(begin == -1)
            break;
    }
    if(List1.size()!=0){
        for(i=0;i<List1.size()-1;i++){
            printf("%05d %d %05d\n",List1[i].begin,List1[i].value,List1[i+1].begin);
        }
        printf("%05d %d -1\n",List1[i].begin,List1[i].value);
    }
    if(List2.size()!=0){
        for(i=0;i<List2.size()-1;i++){
            printf("%05d %d %05d\n",List2[i].begin,List2[i].value,List2[i+1].begin);
        }
        printf("%05d %d -1\n",List2[i].begin,List2[i].value);
    }
    system("pause");
    return 0;
}