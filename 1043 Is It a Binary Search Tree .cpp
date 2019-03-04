#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;

typedef struct Tree{
	Tree * left;
	Tree * right;
	int ele;
}Tree;
 
vector<int> righta,rightb;
vector<int> post,seq;
 
void insert(Tree *&root,int num){
	if(root==NULL){
		root = (Tree *)malloc(sizeof(Tree));
		root->ele = num;
		root->left = NULL;
		root->right = NULL;
		return;
	}
 
	if(num<root->ele){
		insert(root->left,num);
	}else{
		insert(root->right,num);
	}
}
 
void preOrder(Tree *root){//前序
	if(root==NULL)return;
	righta.push_back(root->ele);
	preOrder(root->left);
	preOrder(root->right);
}
 
void ARL(Tree *root){//根右左mirror的前序
	if(root==NULL)return;
	rightb.push_back(root->ele);
	ARL(root->right);
	ARL(root->left);
}
 
void postOrder(Tree *root){//后序
	if(root==NULL)return;
	postOrder(root->left);
	postOrder(root->right);
	post.push_back(root->ele);
}
 
void print(vector<int> vc){
	vector<int>::iterator ite = vc.begin();
 
	bool flg = true;
	for(;ite!=vc.end();++ite){
		if(!flg){
			printf(" %d",*ite);
		}else{
			printf("%d",(*ite));
			flg = false;
		}
	}
	printf("\n");
}
 
void change(Tree *root){
	if(root==NULL)return;
	Tree *temp = root->left;
	root->left = root->right;
	root->right = temp;
	change(root->left);
	change(root->right);
}
 
int main(){
	int n,i,num;
	Tree *root = NULL;
	scanf("%d",&n);
	for(i=0;i<n;++i){
		scanf("%d",&num);
		seq.push_back(num);
		insert(root,num);
	}
	
	preOrder(root);
	ARL(root);
	if(righta==seq){
		printf("YES\n");
		post.clear();
		postOrder(root);
		print(post);
	}else if(rightb==seq){
		printf("YES\n");
		change(root);
		post.clear();
		postOrder(root);
		print(post);
	}else
		printf("NO\n");
    system("pause");
    return 0;
}