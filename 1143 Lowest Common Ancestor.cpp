#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
//给出BST的先序数组，可以确定整个树是什么样的
//运行超时的测试点没有过



int pre[10001];
unordered_map<int,int> search;

void Judge(int prel,int prer,int a,int b){
    int root = pre[prel];
    int indexa = search[a];
    int indexb = search[b];
    int left,right,i;
    if(root == a){
        printf("%d is an ancestor of %d.\n",a,b);
        return ;
    }
    else if(root == b){
        printf("%d is an ancestor of %d.\n",b,a);
    }
    for(i=prel+1;i<=prer;i++){
        if(pre[i]>root){
            right = i;
            break;
        }
    }
    if((indexa>=right && indexb<right) || (indexa<right && indexb>=right)){
        printf("LCA of %d and %d is %d.\n",a,b,root);
        return;
    }
    else if(indexa<=right && indexb<=right){
        Judge(prel+1,right-1,a,b);
        return;
    }
    else if(indexa>=right && indexb>=right){
        Judge(right,prer,a,b);
        return;
    }
    return ;
}

int main(){
    int n,m,i,j;
    cin>>m>>n;
    for(i=1;i<=n;i++){ 
        cin>>pre[i];
        search[pre[i]] = i;
    }
    int a,b;
    for(i=0;i<m;i++){
        cin>>a>>b;
        if(search[a]==0 && search[b] ==0 ){
            printf("ERROR: %d and %d are not found.\n",a,b);
            continue;
        }
        else if(search[a] == 0){
            printf("ERROR: %d is not found.\n",a);
            continue;
        }
        else if(search[b] == 0){
            printf("ERROR: %d is not found.\n",b);
            continue;
        }
        Judge(1,n,a,b);
    }
    system("pause");
    return 0;
}

