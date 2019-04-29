#include<iostream>
#include<vector>
using namespace std;

//用一个hash, 一开始很简单只有20分 忽略了sharing的部分可能是在中间的
//看了柳神的答案之后 才觉得应该在Hash中添加一个flag

struct node{
    int next;
    int flag;
}Hash[100000];

int main(){
    int w1,w2,n;
    cin>>w1>>w2>>n;
    int a,b;
    char ch;
    for(int i=0;i<n;i++){
        cin>>a>>ch>>b;
        Hash[a].next = b;
        Hash[a].flag = 0;
    }
    for(int i=w1;i!=-1;i = Hash[i].next){
        Hash[i].flag = 1;
    }
    for(int i = w2;i!=-1;i=Hash[i].next){
        if(Hash[i].flag == 1){
            printf("%05d",i);
            system("pause");
            return 0;
        }
    }
    printf("-1");
    system("pause");
    return 0;

}
