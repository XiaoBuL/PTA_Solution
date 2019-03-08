#include<iostream>
#include<vector>
using namespace std;
int pre[50000];
int in[50000];

//运行超时错误，还是有点bug

void first(int prel,int prer,int inl,int inr){
    int root = pre[prel];
    int right;
    int i;
    if(inl==inr){
        cout<<root<<endl;
        return ;
    }
    for(i=inl;i<=inr;i++){
        if(in[i]==root)
            break;
    }
    if(i==inl){
        first(prel+1,prer,inl+1,inr);
        return;
    }
    else
        right = i - 1;   
    int newroot  = pre[prel+1];
    inr = right;
    if(inr - inl == 1 ){
        if(newroot == in[inl])
            cout<<in[inr]<<endl;
        else if(newroot == in[inr])
            cout<<in[inl]<<endl;
        return ;
    }

    first(prel+1,prel + right - inl,inl,right);
    return;
}

int main(){
    int n,i;
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>pre[i];
    }
    for(i=1;i<=n;i++){
        cin>>in[i];
    }
    first(1,n,1,n);
    system("pause");
    return 0;
}