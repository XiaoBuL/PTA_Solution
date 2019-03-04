#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int n;
int in[31],post[31];

struct node{
    int data;
    node* lchild;
    node* rchild;
};
node* create(int postL,int postR,int inL,int inR){
    if(postL>postR)
        return NULL;
    node* root = new node;
    root->data = post[postR];
    int i;
    for(i = inL;i<=inR;i++){
        if(in[i] == post[postR])
            break;
    }
    int left = i - inL;
    root->lchild = create(postL,postL+left-1,inL,i-1);
    root->rchild = create(postL+left,postR-1,i+1,inR);
    return root;
}

void BFS(node* root){
    int count = 0;
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node* temp = q.front();
        q.pop();
        cout<<temp->data;
        count++;
        if(count<n)
            cout<<" ";
        if(temp->lchild!=NULL)
            q.push(temp->lchild);
        if(temp->rchild!=NULL)
            q.push(temp->rchild);
    }
}

int main(){
    int i;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>post[i];
    }        
    for(i=0;i<n;i++)
        cin>>in[i];
    node* root = create(0,n-1,0,n-1);
    BFS(root);
    system("pause");
    return 0;
}