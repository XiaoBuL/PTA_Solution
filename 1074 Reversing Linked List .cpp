#include<iostream>
#include<vector>

using namespace std;

struct  node
{
    int begin;
    int end;
    int data;
};

int main(){
    int first,n,k;
    cin>>first>>n>>k;
    int i,j;
    vector<node> in,link;
    vector<node> out;
    node temp;
    for(i=0;i<n;i++){
        cin>>temp.begin>>temp.data>>temp.end;
        if(temp.begin == first)
            link.push_back(temp);
        in.push_back(temp);
    }
    for(i=1;i<n;i++){
        first = link[i-1].end;
        for(j=0;j<n;j++){
            if(first == in[j].begin){
                link.push_back(in[j]);
                break;
            }
        } 
    }
    node index;
    if(k>n)
        k = n;
    for(i=k-1;i>=0;i--){
        index.begin = link[i].begin;
        index.data = link[i].data;
        if(i==0){
            if(k<n)
                index.end = link[k].begin;
            else 
                index.end = -1;
        }
        else{
            index.end = link[i-1].begin;
        }
        out.push_back(index);
    }
    for(i=k;i<n;i++){
        index.begin = link[i].begin;
        index.data = link[i].data;
        if(i==n-1)
            index.end = -1;
        else{
            index.end = link[i+1].begin;
        }
        out.push_back(index);
    }
    for(i=0;i<out.size()-1;i++){
        printf("%05d %d %05d\n",out[i].begin,out[i].data,out[i].end);
    }
    printf("%05d %d -1\n",out[i].begin,out[i].data);
    system("pause");
    return 0;
}