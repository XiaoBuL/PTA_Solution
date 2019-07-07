#include<iostream>
#include<vector>
#include<stdlib.h>
#include<string>
using namespace std;


//这题是真的不会
//Push进来的是先序，pop出去的顺序是中序
//根据中序和先序列 输出后序排序
//如何通过一棵树的其他遍历生成第三个遍历

vector<int> post;
vector<int> in;
vector<int> pre;

void post_order(int in_left,int pre_left,int n){
    //递归完成条件
    if(n==0)
        return ;
    if(n==1){
        post.push_back(pre[pre_left]);
        return ;
    }
    int root = pre[pre_left];
    int i,num;
    int inroot_index;
    for(i=0;i<in.size();i++){
        if(in[i] == root)
            inroot_index = i;  
    }
    num = inroot_index - in_left;
    //左子树遍历
    post_order(in_left,pre_left+1,num);    
    //右子树遍历
    post_order(inroot_index+1,pre_left + num +1,n-num-1);
    post.push_back(root);

}

int main(){
    int n,i;
    cin>>n;
    vector<int> s;
    string temp;
    int num;
    getline(cin,temp);
    for(i=0;i<2*n;i++){
        getline(cin,temp);
        if(temp.size()>3){
            string a = temp.substr(5,temp.size()-5);
            num = atoi(a.c_str());
            s.push_back(num);
            pre.push_back(num);   
        }
        else{
            num = s.back();
            s.pop_back();
            in.push_back(num);        
        }
    }    
    post_order(0,0,n);
    for(i=0;i<n;i++){
        if(i==n-1)
            cout<<post[i];
        else
            cout<<post[i]<<" ";
    }
    system("pause");
    return 0;
}