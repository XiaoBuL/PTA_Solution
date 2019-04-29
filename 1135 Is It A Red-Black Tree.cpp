#include<iostream>
#include<vector>
#include<stdlib.h>
#include<algorithm>
using namespace std;
//红黑树，判断一棵树是否是红黑树，一开始我的想法是不想建树的，但是看了网上的解法还是建树简单
struct node{
    int val;
    struct node *left;
    struct node *right;
};

//建立一棵二叉树
node* build(node *root,int val){
    if(root==NULL){
        root = new node();
        root->val = val;
        root->left = root->right = NULL;
    }
    else if(abs(val)<abs(root->val)){
        root->left = build(root->left,val);
    }
    else 
        root->right = build(root->right,val);
    return root;
}

//判断红节点的子节点是否是黑色节点
int Judge1(node *root){
    if(root==NULL) 
        return 1;
    if(root->val<0){
        if(root->left!=NULL && root->left->val<0)
            return 0;
        if(root->right!=NULL&&root->right->val<0)
            return 0;
    }    
    return Judge1(root->left)&&Judge1(root->right);
}       //判断红节点的子节点是否都是黑节点


int getblack(node *root){
    if(root == NULL)    return 0;
    int left = getblack(root->left);
    int right = getblack(root->right);
    if(root->val >0)
        return left>right?left:right + 1;
    else
        return left>right?left:right;
}
int Judge2(node *root){
    if(root==NULL)  return 1;
    int left = getblack(root->left);
    int right = getblack(root->right);
    if(left!=right)
        return 0;        
    return Judge2(root->left)&&Judge2(root->right);
}

int main(){
    int k,n,num;
    cin>>k;
    for(int i=0;i<k;i++){
        cin>>n;
        node *root = NULL;
        for(int j = 1;j<=n;j++){
            cin>>num;
            root = build(root,num);
        }
        if(root->val<0 || !Judge1(root) || !Judge2(root) )
            cout<<"No"<<endl;
        else
            cout<<"Yes"<<endl;
    }
    system("pause");
    return 0;    
}